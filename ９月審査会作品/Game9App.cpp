#include "common.h"
#include "GAME/Manager/Manager.h"
#include "GAME/Camera/GameCamera.h"
#include "GAME/Stage/Stage.h"

class Game9App : public AppNative {
private:
	ManagerSP g_manager = ManagerSP(new Manager);
	GameCameraSP g_camera = GameCameraSP(new GameCamera);
	StageSP g_stage = StageSP(new Stage);

	gl::Light* light;
	bool istouch = false;

	// enum�Ŏw�肵������������i�[����
	Vec2i touch_direction = Vec2i(DEFAULT, DEFAULT);

	Vec2f touch_pos = Vec2f(0, 0);

public:
	void setup();
	void update();
	void draw();

	// �^�b�`����------------------------------
	void prepareSettings(Settings* settings) override {
		// �}���`�^�b�`��L���ɂ���
		settings->enableMultiTouch();
	}

	// �ȉ��A�^�b�`����ŌĂяo����郁���o�֐�
	// �^�b�`�J�n����
	void touchesBegan(TouchEvent event) {
		istouch = true;

		// �^�b�`��������擾
		// �}���`�^�b�`�̎��͕����̃^�b�`��񂪊i�[���ꂤ��
		const std::vector<TouchEvent::Touch>& touches = event.getTouches();
		for (const TouchEvent::Touch& touch : touches)
		{
			touch_pos = touch.getPos();

			//// ���O�̈ʒu���擾�ł���
			//Vec2f touch_prev_pos = touch.getPrevPos();

			//// �����^�b�`���������鎯�ʎq
			//uint32_t touch_id = touch.getId();

			//// �^�b�`����̎���
			//double touch_time = touch.getTime();
		}
	}

	// �^�b�`�ړ�����
	void touchesMoved(TouchEvent event)
	{
		const std::vector<TouchEvent::Touch>& touches = event.getTouches();

		for (const TouchEvent::Touch& touch : touches)
		{
			Vec2f move_pos = touch.getPos();

			// �^�b�`�J�n�ʒu�ƈړ���̈ʒu���r
			// �w���W
			if (move_pos.x < touch_pos.x - 10.f)
			{
				touch_direction.x = LEFT;
			}

			else if (move_pos.x > touch_pos.x + 10.f)
			{
				touch_direction.x = RIGHT;
			}

			// �x���W
			if (move_pos.y < touch_pos.y - 20.f)
			{
				touch_direction.y = UP;
			}

			else if (move_pos.y > touch_pos.y + 20.f)
			{
				touch_direction.y = DOWN;
			}
		}
	};

	// �^�b�`��������(����p�l������w�𗣂���)
	void touchesEnded(TouchEvent event)
	{
		istouch = false;
		touch_pos = Vec2f(0, 0);
		touch_direction.x = touch_direction.y = DEFAULT;
	};
};

void Game9App::setup()
{
	g_camera->setup();
	g_manager->setup();

	light = new gl::Light(gl::Light::DIRECTIONAL, 0);
	light->setAmbient(Color(1, 1, 1));
	light->setDiffuse(Color(1, 1, 1));
	light->setDirection(Vec3f(0, 1, 1));

	gl::enable(GL_TEXTURE_2D);
	gl::enable(GL_CULL_FACE);
	gl::enable(GL_LIGHTING);
	gl::enable(GL_NORMALIZE);

	glLightModeli(GL_LIGHT_MODEL_COLOR_CONTROL,
				  GL_SEPARATE_SPECULAR_COLOR);

	gl::enableDepthRead();
	gl::enableDepthWrite();
}


void Game9App::update()
{
	g_camera->update();

	g_manager->update(touch_direction, istouch);
	g_camera->target_update(touch_direction);
}

void Game9App::draw()
{
	gl::clear(Color(0, 0, 0));

	g_camera->SetCamera();

	light->enable();

	g_manager->draw();
	g_stage->draw();
}

CINDER_APP_NATIVE(Game9App, RendererGl)


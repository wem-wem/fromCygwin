#include "common.h"
#include "GAME/Manager/Manager.h"
#include "GAME/Camera/GameCamera.h"
#include "GAME/Stage/Stage.h"
#include "TITLE/Title.h"
#include "RESULT/Result.h"
#include "GAME/UI/UI.h"

class Game9App : public AppNative {
private:
	TitleSP title = TitleSP(new Title);
	ManagerSP g_manager = ManagerSP(new Manager);
	GameCameraSP g_camera = GameCameraSP(new GameCamera);
	StageSP g_stage = StageSP(new Stage);
	ResultSP result = ResultSP(new Result);
	GameUISP UI = GameUISP(new GameUI);

#pragma region ����
	audio::BufferPlayerNodeRef TITLE_BGM;
	audio::BufferPlayerNodeRef SELECT_SE;
	audio::BufferPlayerNodeRef RESULT_BGM;
	audio::BufferPlayerNodeRef ITEM_GET_SE;
	audio::BufferPlayerNodeRef JUMP_SE;
	audio::BufferPlayerNodeRef DAMAGE_SE;

	audio::GainNodeRef TITLE_BGM_gain;
	audio::GainNodeRef SELECT_SE_gain;
	audio::GainNodeRef RESULT_BGM_gain;
	audio::GainNodeRef ITEM_GET_SE_gain;
	audio::GainNodeRef JUMP_SE_gain;
	audio::GainNodeRef DAMAGE_SE_gain;
#pragma endregion

	gl::Light* light;
	bool istouch = false;
	unsigned int onetime_score;
	unsigned int scene = TITLE;

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
	void touchesBegan(TouchEvent event)
	{
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

			// ���O�̈ʒu���擾�ł���
			Vec2f touch_prev_pos = touch.getPrevPos();

			// ���X�́u�ŏ��Ƀ^�b�`�����n�_�𒆐S�ɏ㉺���E�Ɉړ��v���������̂�
			// �u���O�̈ʒu�Ɣ�ׂĂǂ̕����ɓ��������v�ŕ�����؂�ւ���悤�ɕύX(��a������) 

			// �^�b�`�J�n�ʒu�ƈړ���̈ʒu���r
			// �w���W
			//if (move_pos.x < touch_pos.x - 10.f)
			if (move_pos.x < touch_prev_pos.x - 2.f)
			{
				touch_direction.x = LEFT;
			}

			//else if (move_pos.x > touch_pos.x + 10.f)
			else if (move_pos.x > touch_prev_pos.x + 2.f)
			{
				touch_direction.x = RIGHT;
			}

			// �x���W
			//if (move_pos.y < touch_pos.y - 20.f)
			if (move_pos.y < touch_prev_pos.y - 2.f)
			{
				touch_direction.y = UP;
			}

			//else if (move_pos.y > touch_pos.y + 20.f)
			else if (move_pos.y > touch_prev_pos.y + 2.f)
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
#pragma region �T�E���h
	setAudioPlayer(TITLE_BGM, TITLE_BGM_gain, "BGM/title_BGM.mp3");
	setAudioPlayer(SELECT_SE, SELECT_SE_gain, "SE/se_maoudamashii_system27.mp3");
	setAudioPlayer(RESULT_BGM, RESULT_BGM_gain, "BGM/result_BGM.mp3");
	setAudioPlayer(ITEM_GET_SE, ITEM_GET_SE_gain, "SE/se_maoudamashii_system24.mp3");
	setAudioPlayer(JUMP_SE, JUMP_SE_gain, "SE/jump.mp3");
	setAudioPlayer(DAMAGE_SE, DAMAGE_SE_gain, "SE/damage.mp3");
#pragma endregion

	Rand::randomize();
	title->setup();
	g_camera->setup();
	g_manager->setup();
	result->setup();

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
	switch (scene)
	{
		case TITLE:
			TITLE_BGM_gain->setValue(0.3f);
			SELECT_SE_gain->setValue(0.3f);

			// ���U���g��BGM���~
			if (RESULT_BGM->isEnabled())
			{
				RESULT_BGM->stop();
			}

			// BGM�����[�v�Đ�
			if (!TITLE_BGM->isEnabled())
			{
				TITLE_BGM->start();
			}

			title->update(istouch, scene, SELECT_SE);
			break;

		case GAME:
			TITLE_BGM_gain->setValue(0.2f);
			ITEM_GET_SE_gain->setValue(0.4f);
			JUMP_SE_gain->setValue(0.4f);
			DAMAGE_SE_gain->setValue(0.4f);

			// ���U���g��BGM���~
			if (RESULT_BGM->isEnabled())
			{
				RESULT_BGM->stop();
			}

			// BGM�����[�v�Đ�
			if (!TITLE_BGM->isEnabled())
			{
				TITLE_BGM->start();
			}

			g_camera->update();
			g_manager->update(touch_direction, istouch, scene, onetime_score);
			g_camera->target_update(touch_direction);
			break;

		case RESULT:
			RESULT_BGM_gain->setValue(0.3f);

			// �^�C�g����BGM���~
			if (TITLE_BGM->isEnabled())
			{
				TITLE_BGM->stop();
			}

			// BGM�����[�v�Đ�
			if (!RESULT_BGM->isEnabled())
			{
				RESULT_BGM->start();
			}

			result->update(onetime_score);
			result->getTouch(scene, SELECT_SE, istouch, onetime_score);
			break;
	}
}

void Game9App::draw()
{
	gl::clear(Color(0, 0, 0));

	g_camera->SetCamera();
	light->enable();

	switch (scene)
	{
		case TITLE:
			title->draw();
			break;

		case GAME:
			g_manager->draw();
			g_stage->draw();
			break;

		case RESULT:
			result->draw();
			break;
	}

	light->disable();
}

CINDER_APP_NATIVE(Game9App, RendererGl)



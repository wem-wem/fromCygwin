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

	// enumで指定した操作方向を格納する
	Vec2i touch_direction = Vec2i(DEFAULT, DEFAULT);

	Vec2f touch_pos = Vec2f(0, 0);

public:
	void setup();
	void update();
	void draw();

	// タッチ操作------------------------------
	void prepareSettings(Settings* settings) override {
		// マルチタッチを有効にする
		settings->enableMultiTouch();
	}

	// 以下、タッチ操作で呼び出されるメンバ関数
	// タッチ開始操作
	void touchesBegan(TouchEvent event) {
		istouch = true;

		// タッチ操作情報を取得
		// マルチタッチの時は複数のタッチ情報が格納されうる
		const std::vector<TouchEvent::Touch>& touches = event.getTouches();
		for (const TouchEvent::Touch& touch : touches)
		{
			touch_pos = touch.getPos();

			//// 直前の位置も取得できる
			//Vec2f touch_prev_pos = touch.getPrevPos();

			//// 複数タッチを見分ける識別子
			//uint32_t touch_id = touch.getId();

			//// タッチ操作の時刻
			//double touch_time = touch.getTime();
		}
	}

	// タッチ移動操作
	void touchesMoved(TouchEvent event)
	{
		const std::vector<TouchEvent::Touch>& touches = event.getTouches();

		for (const TouchEvent::Touch& touch : touches)
		{
			Vec2f move_pos = touch.getPos();

			// タッチ開始位置と移動後の位置を比較
			// Ｘ座標
			if (move_pos.x < touch_pos.x - 10.f)
			{
				touch_direction.x = LEFT;
			}

			else if (move_pos.x > touch_pos.x + 10.f)
			{
				touch_direction.x = RIGHT;
			}

			// Ｙ座標
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

	// タッチ完了操作(操作パネルから指を離した)
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


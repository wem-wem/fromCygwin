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

#pragma region 音響
	audio::BufferPlayerNodeRef TITLE_BGM;
	audio::BufferPlayerNodeRef GAME_BGM;
	audio::BufferPlayerNodeRef RESULT_BGM;
	audio::BufferPlayerNodeRef SELECT_SE;
	audio::BufferPlayerNodeRef SHOT_SE;
	audio::BufferPlayerNodeRef HIT_SE;

	audio::GainNodeRef TITLE_BGM_gain;
	audio::GainNodeRef GAME_BGM_gain;
	audio::GainNodeRef RESULT_BGM_gain;
	audio::GainNodeRef SELECT_SE_gain;
	audio::GainNodeRef SHOT_SE_gain;
	audio::GainNodeRef HIT_SE_gain;
#pragma endregion

	gl::Light* light;
	bool istouch = false;
	unsigned int onetime_score;
	unsigned int scene = RESULT;

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
	void touchesBegan(TouchEvent event)
	{
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

			// 直前の位置も取得できる
			Vec2f touch_prev_pos = touch.getPrevPos();

			// 元々は「最初にタッチした地点を中心に上下左右に移動」だったものを
			// 「直前の位置と比べてどの方向に動いたか」で方向を切り替えるように変更(違和感あり) 

			// タッチ開始位置と移動後の位置を比較
			// Ｘ座標
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

			// Ｙ座標
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
#pragma region サウンド
	setAudioPlayer(TITLE_BGM, TITLE_BGM_gain, "BGM/title_BGM.mp3");
	setAudioPlayer(GAME_BGM, GAME_BGM_gain, "BGM/game_BGM.mp3");
	setAudioPlayer(RESULT_BGM, RESULT_BGM_gain, "BGM/result_BGM.mp3");
	setAudioPlayer(SELECT_SE, SELECT_SE_gain, "SE/se_maoudamashii_system27.mp3");
	setAudioPlayer(SHOT_SE, SHOT_SE_gain, "SE/shot_SE.mp3");
	setAudioPlayer(HIT_SE, HIT_SE_gain, "SE/hit_SE.mp3");
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

			// リザルトと本編のBGMを停止
			if (GAME_BGM->isEnabled())
			{
				GAME_BGM->stop();
			}
			if (RESULT_BGM->isEnabled())
			{
				RESULT_BGM->stop();
			}

			// タイトルBGMをループ再生
			if (!TITLE_BGM->isEnabled())
			{
				TITLE_BGM->start();
			}

			title->update(istouch, scene, SELECT_SE);
			break;

		case GAME:
			GAME_BGM_gain->setValue(0.2f);
			SHOT_SE_gain->setValue(0.3f);
			HIT_SE_gain->setValue(0.3f);

			// タイトルとリザルトのBGMを停止
			if (TITLE_BGM->isEnabled())
			{
				TITLE_BGM->stop();
			}
			if (RESULT_BGM->isEnabled())
			{
				RESULT_BGM->stop();
			}

			// 本編BGMをループ再生
			if (!GAME_BGM->isEnabled())
			{
				GAME_BGM->start();
			}

			g_camera->update();
			g_manager->update(touch_direction, istouch, scene, onetime_score,
							  SHOT_SE, HIT_SE);
			g_camera->target_update(touch_direction);
			break;

		case RESULT:
			RESULT_BGM_gain->setValue(0.3f);

			// ゲームとタイトルのBGMを停止
			if (GAME_BGM->isEnabled())
			{
				GAME_BGM->stop();
			}
			if (TITLE_BGM->isEnabled())
			{
				TITLE_BGM->stop();
			}

			// BGMをループ再生
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



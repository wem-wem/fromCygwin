#include "common.h"
#include "Title/Title.h"

#include "Player/Player.h"
#include "Ground/Ground.h"
#include "FallCube/FallCube.h"
#include "Item/Item.h"
#include "GameUI/GameUI.h"

#include "Result/Result.h"


class Box_BoxApp : public AppNative {
private:
	// ライト
	std::unique_ptr<gl::Light> light;

	// カメラ
	CameraPersp camera;

	// クラスの呼び出し
	Title title;

	Player player;
	Ground ground;
	FallCube fallcube;
	Item item;
	GameUI game_ui;

	Result result;

	// シーン切り替え用変数
	unsigned int scene;

	// スコアを一時的に保存する変数
	unsigned int onetime_score;
	unsigned int time_count;

public:
	void setup();
	void keyDown(KeyEvent event);
	void keyUp(KeyEvent event);
	void update();
	void draw();
};


void Box_BoxApp::setup()
{
	// ライトの準備--------------------------------------------------------
	// 平行光源を１つ用意
	light = std::unique_ptr<gl::Light>(new gl::Light(gl::Light::DIRECTIONAL, 0));
	light->setAmbient(Color(0.0, 0.0, 0.0));
	light->setDiffuse(Color(1.0, 1.0, 1.0));
	light->setDirection(Vec3f(0.0, 1.0, 0.5)); // 光は真上から真下を照らす


	// カメラの準備--------------------------------------------------------
	camera = CameraPersp(getWindowWidth(), getWindowHeight(),
		35.0, 200.0, 1000.0);

	camera.lookAt(Vec3f(0.0, 300.0, 600.0), // Y軸300, Z軸300の地点から
		Vec3f(0.0, 0.0, 0.0));	// (0, 0, 0)の地点を見るカメラ


	// カリングON(手前の面のみを表示)
	gl::enable(GL_CULL_FACE);

	// 頂点カラーを対象にしてライティングの計算を行う
	gl::enable(GL_COLOR_MATERIAL);

	// ライティングON
	gl::enable(GL_LIGHTING);

	// 法線を正規化する
	gl::enable(GL_NORMALIZE);

	gl::enableDepthRead();
	gl::enableDepthWrite();

	// 文字の周りの黒い枠が消えたよ！
	gl::enableAlphaBlending();

	// 変数の初期化-------------------------------------
	onetime_score = 0;
	time_count = 0;


	// シーン切り替え用変数-----------------------------------------
	scene = RESULT;


	// 他クラスのフォント読み込み-----------------------------------------
	title.setup();
	player.setup();
	game_ui.setup();
	result.setup();
}


void Box_BoxApp::keyDown(KeyEvent event)
{
	switch (scene){
	case TITLE:
		title.keyDown(event, scene);
		break;

	case GAME:
		player.keyDown(event);
		break;

	case RESULT:
		result.keyDown(event, scene, time_count, onetime_score);
		break;
	}
}


void Box_BoxApp::keyUp(KeyEvent event)
{
	switch (scene){
	case TITLE:
		break;

	case GAME:
		player.keyUp(event);
		break;

	case RESULT:
		break;
	}
}

void Box_BoxApp::update()
{
	switch (scene){
	case TITLE:
		camera.lookAt(Vec3f(0.0, 300.0, 600.0), // Y軸300, Z軸300の地点から
			Vec3f(0.0, 0.0, 0.0));	// (0, 0, 0)の地点を見るカメラ

		title.update();
		break;

	case GAME:
		camera.lookAt(Vec3f(0.0, 300.0, 300.0), // Y軸300, Z軸300の地点から
			Vec3f(0.0, 0.0, 0.0));	// (0, 0, 0)の地点を見るカメラ

		player.SetReference(&fallcube, &item, &game_ui);
		player.update(onetime_score, scene);
		fallcube.update();
		item.update();
		game_ui.update(onetime_score, scene, item, fallcube);

		// 【TOTAL TIME】測定用のタイムを加算
		time_count++;
		break;

	case RESULT:
		camera.lookAt(Vec3f(0.0, 300.0, 600.0), // Y軸300, Z軸300の地点から
			Vec3f(0.0, 0.0, 0.0));	// (0, 0, 0)の地点を見るカメラ

		player.get_A = player.get_D = player.get_S = player.get_W = player.get_SPACE = false;
		

#pragma region オブジェクトの再配置
		// プレイヤーの変数初期化
		player.pos = Vec3f(0, 15, 0);
		player.gravity = 0;
		player.shadow_size = 8.0f;

		// 落下キューブの初期化
		for (unsigned int i = 0; i < fallcube.cube.size(); i++)
		{
			fallcube.cube[i].pos =
				Vec3f(randFloat(-90.0f, 90.0f), randFloat(300.0f, 600.0f), randFloat(-90.0f, 90.0f));

			fallcube.cube[i].shadow_width = 0.0f;
		}

		// アイテムの初期化
		for (unsigned int i = 0; i < item.obj.size(); i++)
		{
			item.obj[i].pos =
				Vec3f(randFloat(-90.0f, 90.0f), randFloat(20.0f, 50.0f), randFloat(-90.0f, 90.0f));
		}

		game_ui._time = 20 * 60;

#pragma endregion
		result.update(onetime_score, time_count);
		break;
	}
}


void Box_BoxApp::draw()
{
	// clear out the window with black
	gl::clear(Color(0.4f, 0.4f, 0.4f));

	// カメラの状態から行列を作成
	// 視点座標変換用と正規化デバイス座標変換用の２つを用意する
	gl::setMatrices(camera);


	// ライティング開始
	light->enable();

	switch (scene){
	case TITLE:
		title.draw();
		break;

	case GAME:
		ground.draw();
		player.draw();
		fallcube.draw();
		item.draw();
		game_ui.draw();
		break;

	case RESULT:
		result.draw();
		break;
	}

	light->disable();
}

CINDER_APP_NATIVE(Box_BoxApp, RendererGl)

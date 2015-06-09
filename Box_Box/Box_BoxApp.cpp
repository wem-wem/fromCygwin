#include "common.h"
#include "Player/Player.h"
#include "Ground/Ground.h"
#include "FallCube/FallCube.h"
#include "Item/Item.h"
#include "Title/Title.h"

class Box_BoxApp : public AppNative {
private:
	// ライト
	std::unique_ptr<gl::Light> light;

	// カメラ
	CameraPersp camera;

	// クラスの呼び出し
	Player player;
	Ground ground;
	FallCube fallcube;
	Item item;
	Title title;

	// シーン切り替え用
	unsigned int scene;
	enum{
		TITLE,
		GAME,
		RESULT
	};

	float rz;

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

	Rand::randomize();
	scene = 0;
	title.setup();
}

void Box_BoxApp::keyDown(KeyEvent event)
{
#pragma region デバッグ機能(シーン切り替え)
	if (event.getCode() == KeyEvent::KEY_t)
	{
		camera.lookAt(Vec3f(0.0, 300.0, 600.0), // Y軸300, Z軸300の地点から
			Vec3f(0.0, 0.0, 0.0));	// (0, 0, 0)の地点を見るカメラ
		scene = TITLE;
		rz = 600.0f;
	}

	if (event.getCode() == KeyEvent::KEY_g)
	{
		scene = GAME;
		camera.lookAt(Vec3f(0.0, 300.0, 300.0), // Y軸300, Z軸300の地点から
			Vec3f(0.0, 0.0, 0.0));	// (0, 0, 0)の地点を見るカメラ
	}
#pragma endregion


	switch (scene){
	case TITLE:
		break;

	case GAME:
		player.keyDown(event);
		break;

	case RESULT:
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
		title.update();
		break;

	case GAME:
		player.SetReference(&fallcube, &item);
		player.update();
		fallcube.update();
		item.update();
		break;

	case RESULT:
		break;
	}
}

void Box_BoxApp::draw()
{
	// clear out the window with black
	gl::clear(Color(0.2f, 0.2f, 0.2f));

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
		break;

	case RESULT:
		break;
	}

	light->disable();
}

CINDER_APP_NATIVE(Box_BoxApp, RendererGl)

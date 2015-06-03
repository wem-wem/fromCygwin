#include "common.h"
#include "Player/Player.h"
#include "Ground/Ground.h"
#include "FallCube/FallCube.h"

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

	camera.lookAt(Vec3f(0.0, 300.0, 300.0), // Z軸700の地点から
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

}

void Box_BoxApp::keyDown(KeyEvent event)
{
	player.keyDown(event);
}

void Box_BoxApp::keyUp( KeyEvent event )
{
	player.keyUp(event);
}

void Box_BoxApp::update()
{
	player.update();
	fallcube.update();
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

	ground.draw();

	player.draw();

	fallcube.draw();

	light->disable();
}

CINDER_APP_NATIVE( Box_BoxApp, RendererGl )

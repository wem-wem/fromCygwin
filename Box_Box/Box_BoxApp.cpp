#include "common.h"
#include "Player/Player.h"
#include "Ground/Ground.h"
#include "FallCube/FallCube.h"

class Box_BoxApp : public AppNative {
private:

	// ���C�g
	std::unique_ptr<gl::Light> light;

	// �J����
	CameraPersp camera;

	// �N���X�̌Ăяo��
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
	// ���C�g�̏���--------------------------------------------------------
	// ���s�������P�p��
	light = std::unique_ptr<gl::Light>(new gl::Light(gl::Light::DIRECTIONAL, 0));
	light->setAmbient(Color(0.0, 0.0, 0.0));
	light->setDiffuse(Color(1.0, 1.0, 1.0));
	light->setDirection(Vec3f(0.0, 1.0, 0.5)); // ���͐^�ォ��^�����Ƃ炷


	// �J�����̏���--------------------------------------------------------
	camera = CameraPersp(getWindowWidth(), getWindowHeight(),
		35.0, 200.0, 1000.0);

	camera.lookAt(Vec3f(0.0, 300.0, 300.0), // Z��700�̒n�_����
		Vec3f(0.0, 0.0, 0.0));	// (0, 0, 0)�̒n�_������J����


	// �J�����OON(��O�̖ʂ݂̂�\��)
	gl::enable(GL_CULL_FACE);

	// ���_�J���[��Ώۂɂ��ă��C�e�B���O�̌v�Z���s��
	gl::enable(GL_COLOR_MATERIAL);

	// ���C�e�B���OON
	gl::enable(GL_LIGHTING);

	// �@���𐳋K������
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

	// �J�����̏�Ԃ���s����쐬
	// ���_���W�ϊ��p�Ɛ��K���f�o�C�X���W�ϊ��p�̂Q��p�ӂ���
	gl::setMatrices(camera);

	// ���C�e�B���O�J�n
	light->enable();

	ground.draw();

	player.draw();

	fallcube.draw();

	light->disable();
}

CINDER_APP_NATIVE( Box_BoxApp, RendererGl )

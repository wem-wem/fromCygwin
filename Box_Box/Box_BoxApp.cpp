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
	// ���C�g
	std::unique_ptr<gl::Light> light;

	// �J����
	CameraPersp camera;

	// �N���X�̌Ăяo��
	Title title;

	Player player;
	Ground ground;
	FallCube fallcube;
	Item item;
	GameUI game_ui;

	Result result;

	// �V�[���؂�ւ��p�ϐ�
	unsigned int scene;

	// �X�R�A���ꎞ�I�ɕۑ�����ϐ�
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
	// ���C�g�̏���--------------------------------------------------------
	// ���s�������P�p��
	light = std::unique_ptr<gl::Light>(new gl::Light(gl::Light::DIRECTIONAL, 0));
	light->setAmbient(Color(0.0, 0.0, 0.0));
	light->setDiffuse(Color(1.0, 1.0, 1.0));
	light->setDirection(Vec3f(0.0, 1.0, 0.5)); // ���͐^�ォ��^�����Ƃ炷


	// �J�����̏���--------------------------------------------------------
	camera = CameraPersp(getWindowWidth(), getWindowHeight(),
		35.0, 200.0, 1000.0);

	camera.lookAt(Vec3f(0.0, 300.0, 600.0), // Y��300, Z��300�̒n�_����
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


	// �ϐ��̏�����-------------------------------------
	onetime_score = 0;
	time_count = 0;


	// �V�[���؂�ւ��p�ϐ�-----------------------------------------
	scene = TITLE;


	// ���N���X�̃t�H���g�ǂݍ���-----------------------------------------
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
		camera.lookAt(Vec3f(0.0, 300.0, 600.0), // Y��300, Z��300�̒n�_����
			Vec3f(0.0, 0.0, 0.0));	// (0, 0, 0)�̒n�_������J����

		title.update();
		break;

	case GAME:
		camera.lookAt(Vec3f(0.0, 300.0, 300.0), // Y��300, Z��300�̒n�_����
			Vec3f(0.0, 0.0, 0.0));	// (0, 0, 0)�̒n�_������J����

		player.SetReference(&fallcube, &item);
		player.update(onetime_score);
		fallcube.update();
		item.update();
		game_ui.update(onetime_score, scene);

		// ���U���g�ւ̈ڍs����
		time_count++;
		if (time_count >= 5 * 60){
			scene = RESULT;
			player.get_A = player.get_D = player.get_S = player.get_W = player.get_SPACE = false;
		}
		break;

	case RESULT:
		camera.lookAt(Vec3f(0.0, 300.0, 600.0), // Y��300, Z��300�̒n�_����
			Vec3f(0.0, 0.0, 0.0));	// (0, 0, 0)�̒n�_������J����

		result.update(onetime_score, time_count);
		break;
	}
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

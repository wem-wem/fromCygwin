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

	// �����̎���̍����g����������I
	gl::enableAlphaBlending();

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

#pragma region �T�E���h
	setAudioPlayer(TITLE_BGM, TITLE_BGM_gain, "BGM/title_BGM.mp3");
	setAudioPlayer(SELECT_SE, SELECT_SE_gain, "SE/se_maoudamashii_system27.mp3");
	setAudioPlayer(RESULT_BGM, RESULT_BGM_gain, "BGM/result_BGM.mp3");
	setAudioPlayer(ITEM_GET_SE, ITEM_GET_SE_gain, "SE/se_maoudamashii_system24.mp3");
	setAudioPlayer(JUMP_SE, JUMP_SE_gain, "SE/jump.mp3");
	setAudioPlayer(DAMAGE_SE, DAMAGE_SE_gain, "SE/damage.mp3");
#pragma endregion
}


void Box_BoxApp::keyDown(KeyEvent event)
{
	switch (scene){
	case TITLE:
		title.keyDown(event, scene, SELECT_SE);
		break;

	case GAME:
		player.keyDown(event, JUMP_SE);
		break;

	case RESULT:
		result.keyDown(event, scene, time_count, onetime_score, SELECT_SE);
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
#pragma region �^�C�g���̍X�V����
	case TITLE:
		TITLE_BGM_gain->setValue(0.5f);
		SELECT_SE_gain->setValue(0.5f);

		// ���U���g��BGM���~
		if (RESULT_BGM->isEnabled()){
			RESULT_BGM->stop();
		}

		// BGM�����[�v�Đ�
		if (!TITLE_BGM->isEnabled()){
			TITLE_BGM->start();
		}

		camera.lookAt(Vec3f(0.0, 300.0, 600.0), // Y��300, Z��600�̒n�_����
			Vec3f(0.0, 0.0, 0.0));	// (0, 0, 0)�̒n�_������J����

		title.update();
		break;
#pragma endregion


#pragma region �{�҂̍X�V����
	case GAME:
		TITLE_BGM_gain->setValue(0.3f);
		ITEM_GET_SE_gain->setValue(0.5f);
		JUMP_SE_gain->setValue(0.5f);
		JUMP_SE_gain->setValue(0.5f);

		// ���U���g��BGM���~
		if (RESULT_BGM->isEnabled()){
			RESULT_BGM->stop();
		}

		// BGM�����[�v�Đ�
		if (!TITLE_BGM->isEnabled()){
			TITLE_BGM->start();
		}

		camera.lookAt(Vec3f(0.0, 300.0, 300.0), // Y��300, Z��300�̒n�_����
			Vec3f(0.0, 0.0, 0.0));	// (0, 0, 0)�̒n�_������J����

		player.SetReference(&fallcube, &item, &game_ui);
		player.update(onetime_score, scene, ITEM_GET_SE, DAMAGE_SE);
		fallcube.update();
		item.update();
		game_ui.update(onetime_score, scene, item, fallcube);

		// �yTOTAL TIME�z����p�̃^�C�������Z
		time_count++;
		break;
#pragma endregion


#pragma region ���U���g�̍X�V����
	case RESULT:
		RESULT_BGM_gain->setValue(0.5f);

		// �^�C�g����BGM���~
		if (TITLE_BGM->isEnabled()){
			TITLE_BGM->stop();
		}

		// BGM�����[�v�Đ�
		if (!RESULT_BGM->isEnabled()){
			RESULT_BGM->start();
		}

		camera.lookAt(Vec3f(0.0, 300.0, 600.0), // Y��300, Z��600�̒n�_����
			Vec3f(0.0, 0.0, 0.0));	// (0, 0, 0)�̒n�_������J����

		player.get_A = player.get_D = player.get_S = player.get_W = player.get_SPACE = false;
		

#pragma region �I�u�W�F�N�g�̍Ĕz�u
		// �v���C���[�̕ϐ�������
		player.pos = Vec3f(0, 15, 0);
		player.gravity = 0;
		player.shadow_size = 8.0f;

		// �����L���[�u�̏�����
		for (unsigned int i = 0; i < fallcube.cube.size(); i++)
		{
			fallcube.cube[i].pos =
				Vec3f(randFloat(-90.0f, 90.0f), randFloat(300.0f, 600.0f), randFloat(-90.0f, 90.0f));

			fallcube.cube[i].shadow_width = 0.0f;
		}

		// �A�C�e���̏�����
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
#pragma endregion
}


void Box_BoxApp::draw()
{
	// clear out the window with black
	gl::clear(Color(0.4f, 0.4f, 0.4f));

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

#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/TriMesh.h"
#include "cinder/Camera.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Light.h"

// �t�H���g
#include "cinder/Font.h"

//��
#include "cinder/audio/Context.h"
#include "cinder/audio/SamplePlayerNode.h"

//����
#include "cinder/audio/NodeEffects.h"

using namespace ci;
using namespace ci::app;
using namespace std;


// �V�[���؂�ւ��p
enum{
	TITLE,
	GAME,
	RESULT
};


//�I�[�f�B�I��ݒ肷��֐�
static void setAudioPlayer(audio::BufferPlayerNodeRef& Player,
	audio::GainNodeRef& Gain, std::string audioFileName){
	// �o�̓f�o�C�X���Q�b�g
	auto ctx = audio::Context::master();

	// �I�[�f�B�I�f�[�^��ǂݍ���ŏ�����
	audio::SourceFileRef sourceFile = audio::load(loadAsset(audioFileName));
	audio::BufferRef buffer = sourceFile->loadBuffer();
	Player = ctx->makeNode(new audio::BufferPlayerNode(buffer));

	// ���̏����ݒ�
	Gain = ctx->makeNode(new audio::GainNode(1.0f));
	// �ǂݍ��񂾃I�[�f�B�I���o�̓f�o�C�X�Ɋ֘A�t���Ă���
	Player >> Gain >> ctx->getOutput();

	// �o�̓f�o�C�X��L���ɂ���
	ctx->enable();
}
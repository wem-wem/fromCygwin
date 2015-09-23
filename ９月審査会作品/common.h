#pragma once
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/Material.h"
#include "cinder/gl/Light.h"
#include "cinder/ImageIo.h"
#include "cinder/Camera.h"
#include "cinder/ObjLoader.h"
#include "cinder/TriMesh.h"
#include "cinder/rand.h"

// フォント
#include "cinder/Font.h"

//音
#include "cinder/audio/Context.h"
#include "cinder/audio/SamplePlayerNode.h"

//音量
#include "cinder/audio/NodeEffects.h"

using namespace ci;
using namespace ci::app;


// 画面操作時の方向に番号を振る
enum Direction
{
	LEFT = 0,
	RIGHT = 1,
	UP = 2,
	DOWN = 3,
	DEFAULT = 4,
};


// シーン切り替え用
enum SCENE
{
	TITLE = 0,
	GAME = 1,
	RESULT = 2,
};


//オーディオを設定する関数
static void setAudioPlayer(audio::BufferPlayerNodeRef& Player,
						   audio::GainNodeRef& Gain, std::string audioFileName){
	// 出力デバイスをゲット
	auto ctx = audio::Context::master();

	// オーディオデータを読み込んで初期化
	audio::SourceFileRef sourceFile = audio::load(loadAsset(audioFileName));
	audio::BufferRef buffer = sourceFile->loadBuffer();
	Player = ctx->makeNode(new audio::BufferPlayerNode(buffer));

	// 音の初期設定
	Gain = ctx->makeNode(new audio::GainNode(1.0f));
	// 読み込んだオーディオを出力デバイスに関連付けておく
	Player >> Gain >> ctx->getOutput();

	// 出力デバイスを有効にする
	ctx->enable();
}
#pragma once
#include "../../common.h"

// 前回の審査会でパーティクルを使ってる人のを参照(要勉強)
class Particle;
typedef std::shared_ptr<Particle> ParticleSP;

class Particle{
private:
	enum{ PARTICLE_MAX = 30 };		// パーティクルの最大数

	Vec3f pos[PARTICLE_MAX];		// パーティクルポジション
	Vec3f size[PARTICLE_MAX];		// パーティクルサイズ
	Vec3f speed[PARTICLE_MAX];		// パーティクル速度
	ColorA color[PARTICLE_MAX];		// パーティクル色
	int clear_time;					// パーティクルを消す時間制御
	bool is_ready;					// パーティクルの準備ができているかどうか？

public:
	Particle::Particle();

	//パーティクル準備
	void splitCubeInit(Vec3f);

	//パーティクル
	void splitCubeDraw();
};

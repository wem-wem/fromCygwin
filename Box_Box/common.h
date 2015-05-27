#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/TriMesh.h"
#include "cinder/Camera.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Light.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Box_Box2App : public AppNative {
private:
	// 三角ポリゴンの集合体
	TriMesh ground_mesh; // 地面用のメッシュ情報
	TriMesh player_mesh; // 自機用のメッシュ情報
	TriMesh shadow_mesh; // 影用のメッシュ情報

	// ライト
	std::unique_ptr<gl::Light> light;

	// カメラ
	CameraPersp camera;

	float ry; // 全ての物体をＹ軸中心に傾ける

	Vec3f player_pos; // 自機の移動用ベクトル
	float gravity;    // 重力

	Vec2f ground_size;
	bool w, a, s, d, space;
	bool isjumping;

public:
	void setup();
	void keyDown(KeyEvent event);
	void keyUp(KeyEvent event);
	void update();
	void draw();
};

#pragma once
#include "../common.h"
#include "../FallCube/FallCube.h"

class Player{
public:
	Player();
	TriMesh p_mesh; // 自機用のメッシュ情報
	TriMesh shadow_mesh; // 影用のメッシュ情報

	Vec3f pos; // 自機の移動用ベクトル
	Vec3f size;
	float gravity;    // 重力
	float shadow_size;
	float move_speed;

	FallCube* fallcube_ref;
	float fallcube_steps;

	// 自機操作の判定用
	bool get_W, get_A, get_S, get_D, get_SPACE;
	bool isjumping;

	~Player(){};
	void keyDown(KeyEvent event);
	void keyUp(KeyEvent event);
	void SetReference(FallCube* ref);
	bool isCollision_A(); // fallcube の右面と player の左面との衝突判定
	bool isCollision_D(); // fallcube の左面と player の右面との衝突判定
	bool isCollision_W(); // fallcube の手前面と player の奥の面との衝突判定
	bool isCollision_S(); // fallcube の奥の面と player の手前面との衝突判定
	void onCube();
	void update();
	void draw();
};
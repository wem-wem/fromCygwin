#pragma once
#include "../common.h"

class Player{
public:
	Player();
	TriMesh p_mesh; // 自機用のメッシュ情報
	TriMesh shadow_mesh; // 影用のメッシュ情報

	Vec3f pos; // 自機の移動用ベクトル
	float gravity;    // 重力

	// 自機操作の判定用
	bool get_W, get_A, get_S, get_D, get_SPACE;
	bool isjumping;

	~Player(){};
	void keyDown(KeyEvent event);
	void keyUp(KeyEvent event);
	void update();
	void draw();
};
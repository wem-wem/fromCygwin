#pragma once
#include "../common.h"

class Player{
public:
	Player();
	TriMesh p_mesh; // ���@�p�̃��b�V�����
	TriMesh shadow_mesh; // �e�p�̃��b�V�����

	Vec3f pos; // ���@�̈ړ��p�x�N�g��
	float gravity;    // �d��

	// ���@����̔���p
	bool get_W, get_A, get_S, get_D, get_SPACE;
	bool isjumping;

	~Player(){};
	void keyDown(KeyEvent event);
	void keyUp(KeyEvent event);
	void update();
	void draw();
};
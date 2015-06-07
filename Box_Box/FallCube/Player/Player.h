#pragma once
#include "../common.h"
#include "../FallCube/FallCube.h"

class Player{
public:
	Player();
	TriMesh p_mesh; // ���@�p�̃��b�V�����
	TriMesh shadow_mesh; // �e�p�̃��b�V�����

	Vec3f pos; // ���@�̈ړ��p�x�N�g��
	Vec3f size;
	float gravity;    // �d��
	float shadow_size;
	float move_speed;

	FallCube* fallcube_ref;
	float fallcube_steps;

	// ���@����̔���p
	bool get_W, get_A, get_S, get_D, get_SPACE;
	bool isjumping;

	~Player(){};
	void keyDown(KeyEvent event);
	void keyUp(KeyEvent event);
	void SetReference(FallCube* ref);
	bool isCollision_A(); // fallcube �̉E�ʂ� player �̍��ʂƂ̏Փ˔���
	bool isCollision_D(); // fallcube �̍��ʂ� player �̉E�ʂƂ̏Փ˔���
	bool isCollision_W(); // fallcube �̎�O�ʂ� player �̉��̖ʂƂ̏Փ˔���
	bool isCollision_S(); // fallcube �̉��̖ʂ� player �̎�O�ʂƂ̏Փ˔���
	void onCube();
	void update();
	void draw();
};
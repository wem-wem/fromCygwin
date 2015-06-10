#pragma once
#include "../common.h"
#include "../FallCube/FallCube.h"
#include "../Item/Item.h"
#include "../GameUI/GameUI.h"

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
	Item* item_ref;
	GameUI* game_ui_ref;

	Font font;

	// ���@����̔���p
	bool get_W, get_A, get_S, get_D, get_SPACE;
	bool isjumping;

	~Player(){};
	void keyDown(KeyEvent event, audio::BufferPlayerNodeRef& JUMP_SE);
	void keyUp(KeyEvent event);
	void SetReference(FallCube* fc_ref, Item* i_ref, GameUI* ui_ref);
	bool isCollisionFallCube_A(); // fallcube �̉E�ʂ� player �̍��ʂƂ̏Փ˔���
	bool isCollisionFallCube_D(); // fallcube �̍��ʂ� player �̉E�ʂƂ̏Փ˔���
	bool isCollisionFallCube_W(); // fallcube �̎�O�ʂ� player �̉��̖ʂƂ̏Փ˔���
	bool isCollisionFallCube_S(); // fallcube �̉��̖ʂ� player �̎�O�ʂƂ̏Փ˔���
	bool isCollisionFallCube_SPACE(); // fallcube �̉��̖ʂ� player �̎�O�ʂƂ̏Փ˔���
	void isCollisionItem(unsigned int& score, unsigned int& time, audio::BufferPlayerNodeRef& ITEM_GET_SE);
	void setup();
	void update(unsigned int& score, unsigned int& scene, audio::BufferPlayerNodeRef& ITEM_GET_SE);
	void draw();
};
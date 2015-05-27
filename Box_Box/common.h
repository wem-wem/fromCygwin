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
	// �O�p�|���S���̏W����
	TriMesh ground_mesh; // �n�ʗp�̃��b�V�����
	TriMesh player_mesh; // ���@�p�̃��b�V�����
	TriMesh shadow_mesh; // �e�p�̃��b�V�����

	// ���C�g
	std::unique_ptr<gl::Light> light;

	// �J����
	CameraPersp camera;

	float ry; // �S�Ă̕��̂��x�����S�ɌX����

	Vec3f player_pos; // ���@�̈ړ��p�x�N�g��
	float gravity;    // �d��

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

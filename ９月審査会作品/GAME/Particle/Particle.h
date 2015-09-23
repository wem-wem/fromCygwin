#pragma once
#include "../../common.h"

// �O��̐R����Ńp�[�e�B�N�����g���Ă�l�̂��Q��(�v�׋�)
class Particle;
typedef std::shared_ptr<Particle> ParticleSP;

class Particle{
private:
	enum{ PARTICLE_MAX = 30 };		// �p�[�e�B�N���̍ő吔

	Vec3f pos[PARTICLE_MAX];		// �p�[�e�B�N���|�W�V����
	Vec3f size[PARTICLE_MAX];		// �p�[�e�B�N���T�C�Y
	Vec3f speed[PARTICLE_MAX];		// �p�[�e�B�N�����x
	ColorA color[PARTICLE_MAX];		// �p�[�e�B�N���F
	int clear_time;					// �p�[�e�B�N�����������Ԑ���
	bool is_ready;					// �p�[�e�B�N���̏������ł��Ă��邩�ǂ����H

public:
	Particle::Particle();

	//�p�[�e�B�N������
	void splitCubeInit(Vec3f);

	//�p�[�e�B�N��
	void splitCubeDraw();
};

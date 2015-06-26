#include "GameManager.h"

void GameManager::update(AppEnv& env){
	// Player�̌��ݒn���X�V����ׂ� update() ���Ă�
	player->update(env);

	// Player���X�y�[�X�L�[��������������
	// �������ꍇ�ABullet���P����
	// (���̍ۂ�Player�� ���W �� �\������ ���擾)
	if (player->isPushKey_SPACE(env)){
		shot_obj.push_back(BulletSP(new Bullet(player->getPos(),
			player->getDirection())));
	}

	// ��ʂɒe���P�ȏ゠��ꍇ�A�e�̐擪�A�h���X���擾
	auto shot_it = shot_obj.begin();

	// �e���P�ڂ��珈���B
	// �O�̏ꍇ������͂���邪���͒ʂ�Ȃ�
	while (shot_it != shot_obj.end()){
		(*shot_it)->update();

		// ��ʊO�ɏo��������鏈��
		if ((*shot_it)->getPos().x() < -WIDTH / 2 ||
			(*shot_it)->getPos().x() > WIDTH / 2 ||
			(*shot_it)->getPos().y() < -HEIGHT / 2 ||
			(*shot_it)->getPos().y() > HEIGHT / 2)
		{
			shot_it = shot_obj.erase(shot_it++);
		}

		// ���̒e�̃A�h���X�ֈړ�
		shot_it++;

	}
}

void GameManager::draw(){
	// �v���C���[�ƒe�̕`�揈�����܂Ƃ߂ď���
	player->draw();

	// update() �Ɠ����悤�ɁA�e�̐擪�v�f���珇�ɕ`�揈��
	for (auto& shots : shot_obj){
		shots->draw();
	}
}
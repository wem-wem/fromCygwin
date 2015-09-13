#include "Manager.h"

Manager::Manager(){
	shot_timer_ = -1;
	delete_line = -10.0f;
}

void Manager::setup()
{
	player->setup();
	enemy->setup();
}

void Manager::update(Vec2i& direction, bool& istouch)
{
	player->update(direction);
	enemy->update();

	// ��ʂ��^�b�`���ĂP�b���ɒe�𔭎˂���
	if (istouch)
	{
		shot_timer_++;
		if (shot_timer_ == 0)
		{
			// �e���P���X�g�ɒǉ�����
			bullet_obj.push_back(BulletSP(new Bullet(player->getPos())));
		}

		// �P�b�o�߂�����^�C�}�[�����Z�b�g
		else if (shot_timer_ > 60)
		{
			shot_timer_ = -1;
		}
	}

	// �w�𗣂��Ă��^�C�}�[�����Z�b�g
	else
	{
		shot_timer_ = -1;
	}


	// ���X�g�ɒe�̏�񂪂���ꍇ�A���̐擪�A�h���X���擾
	auto bullet_it = bullet_obj.begin();

	// ���X�g�̐擪����Ō�܂Œe���������Ă���
	while (bullet_it != bullet_obj.end())
	{
		(*bullet_it)->update();

		// ��苗���i�񂾂�e����������
		if ((*bullet_it)->getPos().z < delete_line)
		{
			bullet_it = bullet_obj.erase(bullet_it++);
		}

		// ���̒e�̃A�h���X�ֈړ�
		bullet_it++;
	}
}


// �v���C���[�E�G�E�e�̕`����܂Ƃ߂�
void Manager::draw()
{
	player->draw();
	enemy->draw();

	for (auto& bullets : bullet_obj)
	{
		bullets->draw();
	}
}

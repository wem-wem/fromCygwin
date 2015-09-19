#include "Manager.h"

Manager::Manager(){
	shot_timer_ = -1;
	delete_line = -10.0f;

	enemy_timer_ = -1;
	enemy_delete_line_ = 1.f;
}


void Manager::setup()
{
	player->setup();
}


void Manager::update(Vec2i& direction, bool& istouch)
{
	player->update(direction);

#pragma region �e�̔��˂Ə���
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

	// �C�e���[�^�擾
	auto bullet_it = bullet_obj.begin();

	// ���X�g�̐擪����Ō�܂Œe���������Ă���
	while (bullet_it != bullet_obj.end())
	{
		(*bullet_it)->update();
		// ��苗���i�񂾂�e������
		// �e�̏Փ˃t���O��true�ɂȂ��Ă�����
		if ((*bullet_it)->getPos().z < delete_line ||
			(*bullet_it)->isDead())
		{
			bullet_it = bullet_obj.erase(bullet_it);
		}

		// ���̒e�̃A�h���X�ֈړ�
		else
		{	
			bullet_it++;
		}
	}
#pragma endregion

#pragma region �G�̐����Ə���
	enemy_timer_++;
	if (enemy_timer_ == 0)
	{
		enemy_obj.push_back(EnemySP(new Enemy));
	}
	else if (enemy_timer_ >= 150)
	{
		enemy_timer_ = -1;
	}

	// �C�e���[�^�擾
	auto enemy_it = enemy_obj.begin();

	// ���X�g�̐擪����Ō�܂Œe���������Ă���
	while (enemy_it != enemy_obj.end())
	{
		(*enemy_it)->update();

		// ��苗���i�񂾂�G����������
		if ((*enemy_it)->getPos().z > enemy_delete_line_ ||
			(*enemy_it)->isDead())
		{
			enemy_it = enemy_obj.erase(enemy_it);
		}

		else
		{
			// ���̒e�̃A�h���X�ֈړ�
			enemy_it++;
		}
	}
#pragma endregion

	// �����蔻��
	for (auto& bullet : bullet_obj)
	{
		for (auto& enemy : enemy_obj)
		{
			if (collision(enemy, bullet))
			{
				bullet->hit();
				enemy->hit();
			}
		}
	}
}


// �v���C���[�E�G�E�e�̕`����܂Ƃ߂�
void Manager::draw()
{
	player->draw();

	for (auto& enemys : enemy_obj)
	{
		enemys->draw();
	}

	for (auto& bullets : bullet_obj)
	{
		bullets->draw();
	}
}

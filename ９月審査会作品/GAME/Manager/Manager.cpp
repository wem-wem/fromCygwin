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
	UI->setup();
}


void Manager::update(Vec2i& direction, bool& istouch,
					 unsigned int& scene, unsigned int& score)
{
	player->update(direction);
	UI->update();
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
		else if (shot_timer_ > 25)
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

		// ��苗���i�ނ��A�G�ɓ���������폜 (�ǉ��F�c�莞�Ԃ��O�ɂȂ�����)
		if ((*bullet_it)->getPos().z < delete_line ||
			(*bullet_it)->isDead() || UI->getTime() <= 0)
		{
			bullet_it = bullet_obj.erase(bullet_it);
		}
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

		// ��苗���i�ނ��A�e�ɓ���������폜 (�ǉ��F�c�莞�Ԃ��O�ɂȂ�����)
		if ((*enemy_it)->getPos().z > enemy_delete_line_ ||
			(*enemy_it)->isDead() || UI->getTime() <= 0)
		{
			enemy_it = enemy_obj.erase(enemy_it);
		}
		else
		{
			enemy_it++;
		}
	}
#pragma endregion

	// �e�ƓG�̏Փ˔�����P�����[�v�ŏ���
	for (auto& bullet : bullet_obj)
	{
		for (auto& enemy : enemy_obj)
		{
			if (collision(enemy, bullet))
			{
				bullet->hit();
				enemy->hit();
				UI->setScore(UI->getScore() + enemy->AddScore());
			}
		}
	}


	// �c�莞�Ԃ��O�ɂȂ����烊�U���g�ֈړ�
	if (UI->getTime() <= 0)
	{
		scene = RESULT;
		UI->setTime(20 * 60);
		score = UI->getScore();
		UI->setScore(0);

		// �v���C���[�̍��W�̓��Z�b�g����
		player->setPos(Vec3f(0.f, 0.f, 0.f));
		// ***** �J�����A���O���̃��Z�b�g���o�����c�v�C�� ***** //
		camera->setAngle(0.0f);
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
	UI->draw();
}


// �G�ƒe�̏Փ˔���
bool Manager::collision(EnemySP& enemy, BulletSP& bullet)
{
	if (enemy->getPos().x + enemy->getSize().x > bullet->getPos().x &&
		enemy->getPos().x - enemy->getSize().x < bullet->getPos().x &&
		enemy->getPos().y + enemy->getSize().y > bullet->getPos().y &&
		enemy->getPos().y - enemy->getSize().y < bullet->getPos().y &&
		enemy->getPos().z + enemy->getSize().z > bullet->getPos().z &&
		enemy->getPos().z - enemy->getSize().z < bullet->getPos().z)
	{
		return true;
	}

	else
	{
		return false;
	}
}


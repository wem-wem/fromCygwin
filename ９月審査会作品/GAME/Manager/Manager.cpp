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


	// ���X�g�ɒe�̏�񂪂���ꍇ�A���̐擪�A�h���X���擾
	auto bullet_it = bullet_obj.begin();

	// ���X�g�̐擪����Ō�܂Œe���������Ă���
	while (bullet_it != bullet_obj.end())
	{
		(*bullet_it)->update();
		// ��苗���i�񂾂�e����������
		if ((*bullet_it)->getPos().z < delete_line)
		{
			bullet_it = bullet_obj.erase(bullet_it);
		}

		// �G�ɓ��������ꍇ�̏��Ŕ���
		else if((*bullet_it)->getPos().x < 0.f)
		{
		
		}

		else
		{	
			// ���̒e�̃A�h���X�ֈړ�
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

	auto enemy_it = enemy_obj.begin();

	// ���X�g�̐擪����Ō�܂Œe���������Ă���
	while (enemy_it != enemy_obj.end())
	{
		(*enemy_it)->update();

		// ��苗���i�񂾂�G����������
		if ((*enemy_it)->getPos().z > enemy_delete_line_)
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


	//// ���s�P�citerator���񂵂ĂȂ��̂œ��R�ł����A�N������ɃG���[�Œ�~
	//if ((*bullet_it)->getPos().x < (*enemy_it)->getPos().x + (*enemy_it)->getSize().x &&
	//	(*bullet_it)->getPos().x > (*enemy_it)->getPos().x - (*enemy_it)->getSize().x)
	//{
	//	bullet_it = bullet_obj.erase(bullet_it);
	//	enemy_it = enemy_obj.erase(enemy_it);
	//}
	//else
	//{
	//	bullet_it++;
	//	enemy_it++;
	//}


	//// ���s�Q�c��̕ʁX�ɏ����Ă����������܂Ƃ߂āA���ŏ������悤�Ƃ��Ă݂����ʑ厸�s
	////�@�@�@�@��ʂ��\���������t���[�Y
	//for (auto bullet_it = bullet_obj.begin(); bullet_it != bullet_obj.end();)
	//{
	//	for (auto enemy_it = enemy_obj.begin(); enemy_it != enemy_obj.end();)
	//	{
	//		(*bullet_it)->update();
	//		// ��苗���i�񂾂�e����������
	//		if ((*bullet_it)->getPos().z < delete_line)
	//		{
	//			bullet_it = bullet_obj.erase(bullet_it);
	//		}
	//		else
	//		{
	//			// ���̒e�̃A�h���X�ֈړ�
	//			bullet_it++;
	//		}


	//		(*enemy_it)->update();
	//		// ��苗���i�񂾂�G����������
	//		if ((*enemy_it)->getPos().z > enemy_delete_line_)
	//		{
	//			enemy_it = enemy_obj.erase(enemy_it);
	//		}
	//		else
	//		{
	//			// ���̒e�̃A�h���X�ֈړ�
	//			enemy_it++;
	//		}

	//		// ����
	//		if ((*bullet_it)->getPos().x < (*enemy_it)->getPos().x + (*enemy_it)->getSize().x &&
	//			(*bullet_it)->getPos().x > (*enemy_it)->getPos().x - (*enemy_it)->getSize().x)
	//		{
	//			bullet_it = bullet_obj.erase(bullet_it);
	//			enemy_it = enemy_obj.erase(enemy_it);
	//		}
	//		else
	//		{
	//			bullet_it++;
	//			enemy_it++;
	//		}
	//	}
	//}
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

#include "Bullet.h"

Bullet::Bullet(){
	// �摜�̓ǂݍ���
	bullet_image = loadImage(loadAsset("shot.png"));
}

// �X�V����(�K�v�Ȃ��̏����o����)
void Bullet::update(){ 
	//// �X�y�[�X�L�[�������ꂽ��e�����
	//if (getKey_space){
	//	PlayerSP player = PlayerSP(new Player());
	//	obj.push_back({ player->pos, Vec2f(0, 1), true });
	//}

	//// �e�� pos �� speed �̕������ړ�������
	//for (auto& itr : obj){
	//	pos += speed;
	//}

	//// ��ʊO�ɏo����e������
	//for (auto itr : obj){
	//	if (itr.pos.x > getWindowWidth() || itr.pos.x < 0){
	//		if (itr.pos.y > getWindowHeight() || itr.pos.y < 0){
	//			obj.erase;
	//		}
	//	}
	//}
}


void Bullet::draw(){
	// �e�̐������\��������
//	for (auto& itr : obj ){
		gl::pushModelView();
		gl::translate(Vec3f(pos + speed, 0));
		gl::draw(bullet_image);
		gl::popModelView();
//	}
}

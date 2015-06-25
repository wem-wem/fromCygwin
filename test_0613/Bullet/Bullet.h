#pragma once

#include "../Object/Object.h"


class Bullet;
typedef std::shared_ptr<Bullet> BulletSP;

class Bullet : public Object{
private:
	struct BulletStatus{
		// �摜�̕`��p
		Vec2f pos_;
		Vec2f speed_;
		Vec2f view_size_;
		float draw_direction_;

		// �摜�̐؂���p
		Texture tex_;
		Vec2f start_tex_;
		Vec2f tex_size_;

		// ���@�̌����Ă���������i�[
		int obj_direction;
	};

public:
	Bullet(Vec2f, int);

	inline Vec2f getPos(){ return pos_; };

	void update();
	void draw();
};

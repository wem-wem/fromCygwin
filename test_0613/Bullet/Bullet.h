#pragma once

#include "../Object/Object.h"


class Bullet;
typedef std::shared_ptr<Bullet> BulletSP;

class Bullet : public Object{
private:
	struct BulletStatus{
		// 画像の描画用
		Vec2f pos_;
		Vec2f speed_;
		Vec2f view_size_;
		float draw_direction_;

		// 画像の切り取り用
		Texture tex_;
		Vec2f start_tex_;
		Vec2f tex_size_;

		// 自機の向いている方向を格納
		int obj_direction;
	};

public:
	Bullet(Vec2f, int);

	inline Vec2f getPos(){ return pos_; };

	void update();
	void draw();
};

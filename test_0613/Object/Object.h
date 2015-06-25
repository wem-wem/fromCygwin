#pragma once
#include "../common.h"

class Object{
	// privateでは利用出来ないので
	// protected で宣言(今更)
protected:
	// 継承するクラスに必要な変数を宣言
	Vec2f pos_;
	Vec2f speed_;
	Vec2f view_size_;
	float draw_direction_;	// 描画の向きを指定
	Texture tex_;

	Vec2f start_tex_;
	Vec2f tex_size_;

	// 自機とショットの向きの判定に
	int obj_direction;
	enum direction_num{
		UP,
		DOWN,
		LEFT,
		RIGHT,
	};

public:
	Object();
	virtual ~Object(){};	// デストラクタの理解が乏しい…

	void update();
	void draw();
};

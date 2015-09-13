#pragma once
#include "../common.h"

// 全てのオブジェクトが持つ情報
class Object{
protected:
	Vec3f pos_;
	Vec3f speed_;

public:
	Object() = default;
	virtual ~Object() {}

	// 値を渡すだけで数値の変更はしない為、constを付ける
	const Vec3f& getPos(){ return pos_; }

	virtual void setup() {}
	virtual void update() {}
	virtual void draw() {}
};

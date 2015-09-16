#include "Enemy.h"

Enemy::Enemy()
{
	speed_ = Vec3f(0.002f, 0.002f, 0.002f);
	size = Vec2f(2.f, 2.f);
	g_t = 0.f;

	enemy_move = { Vec3f(randFloat(-6.f, 6.f), randFloat(-2.f, 2.f), -10.f),
		Vec3f(randFloat(-5.f, 5.f), randFloat(-2.f, 2.f), randFloat(-9.f, -5.f)),
		Vec3f(randFloat(-3.f, 3.f), randFloat(-2.f, 2.f), randFloat(-9.f, -5.f)),
		Vec3f(randFloat(-3.f, 3.f), randFloat(-2.f, 2.f), 0.f) };

	pos_ = WsbVec3BezierSpline(&enemy_move.g_AncLine0,
							   &enemy_move.g_AncLine1,
							   &enemy_move.g_AncLine2,
							   &enemy_move.g_AncLine3, g_t);

	setup();
}


void Enemy::setup()
{
	obj = new ObjLoader(loadAsset("Enemy/Enemy.obj"));
	obj->load(&mesh, true, true, false);
}


//===========================================================================================
// name... WsbVec3BezierSpline
// work... 3次元空間上のベジェスプライン曲線補間
// arg1... 演算結果
// arg2... アンカー01 ( 始点 )
// arg3... アンカー02 
// arg4... アンカー03 
// arg5... アンカー04 ( 終点 )
// arg6... 0.0f ～ 1.0f 
// ret..... none
// note... none
//===========================================================================================
Vec3f Enemy::WsbVec3BezierSpline(Vec3f* pAnc01, Vec3f* pAnc02,
								 Vec3f* pAnc03, Vec3f* pAnc04,
								 float t)
{
	t = (1.0f < t) ? 1.0f : t;
	t = (0.0f > t) ? 0.0f : t;

	float wkT = (1.0f - t);
	float wkX, wkY, wkZ;
	wkX = wkY = wkZ = 0.0f;

	float T2 = (t*t);
	float T3 = (t*t*t);
	float wkT2 = (wkT*wkT);
	float wkT3 = (wkT*wkT*wkT);

	wkX = ((wkT3)*pAnc01->x);
	wkX = wkX + ((3 * (wkT2))*(t*pAnc02->x));
	wkX = wkX + (((3 * wkT)*(T2))*(pAnc03->x));
	wkX = wkX + ((T3)*pAnc04->x);

	wkY = ((wkT3)*pAnc01->y);
	wkY = wkY + ((3 * (wkT2))*(t*pAnc02->y));
	wkY = wkY + (((3 * wkT)*(T2))*(pAnc03->y));
	wkY = wkY + ((T3)*pAnc04->y);

	wkZ = ((wkT3)*pAnc01->z);
	wkZ = wkZ + ((3 * (wkT2))*(t*pAnc02->z));
	wkZ = wkZ + (((3 * wkT)*(T2))*(pAnc03->z));
	wkZ = wkZ + ((T3)*pAnc04->z);

	return Vec3f(wkX, wkY, wkZ);
}


void Enemy::update()
{
	g_t += speed_.x;

	if (g_t > 1.0f)
	{
		g_t = 0.0f;
	}

	pos_ = WsbVec3BezierSpline(&enemy_move.g_AncLine0,
							   &enemy_move.g_AncLine1,
							   &enemy_move.g_AncLine2,
							   &enemy_move.g_AncLine3,
							   g_t);
}


void Enemy::draw()
{
	gl::pushModelView();
	gl::translate(pos_);
	gl::scale(Vec3f(0.3f, 0.3f, 0.3f));
	gl::draw(mesh);
	gl::popModelView();
}


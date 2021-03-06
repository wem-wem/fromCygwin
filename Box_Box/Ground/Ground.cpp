#include "Ground.h"

Ground::Ground(){
	// 立方体の頂点座標を指定--------------------------------------------------------
	Vec3f vertices[] = {
		// 手前の面
		{ -1, -1, -1 }, { 1, 1, -1 }, { 1, -1, -1 },
		{ -1, -1, -1 }, { -1, 1, -1 }, { 1, 1, -1 },

		// 上の面
		{ -1, 1, -1 }, { -1, 1, 1 }, { 1, 1, 1 },
		{ -1, 1, -1 }, { 1, 1, 1 }, { 1, 1, -1 },

		{ 1, -1, -1 }, { 1, 1, -1 }, { 1, 1, 1 },
		{ 1, -1, -1 }, { 1, 1, 1 }, { 1, -1, 1 },

		{ -1, -1, -1 }, { -1, -1, 1 }, { -1, 1, 1 },
		{ -1, -1, -1 }, { -1, 1, 1 }, { -1, 1, -1 },

		{ -1, -1, -1 }, { 1, -1, 1 }, { -1, -1, 1 },
		{ -1, -1, -1 }, { 1, -1, -1 }, { 1, -1, 1 },

		{ 1, 1, 1 }, { -1, 1, 1 }, { -1, -1, 1 },
		{ 1, 1, 1 }, { -1, -1, 1 }, { 1, -1, 1 },
	};
	g_mesh.appendVertices(&vertices[0], sizeof(vertices) / sizeof(vertices[0]));


	// 頂点毎(面)の色を指定(土台)--------------------------------------------------------
	Color colors[] = {
		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },
		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },

		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },
		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },

		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },
		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },

		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },
		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },

		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },
		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },

		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },
		{ 0.5, 1, 0.5 }, { 0.5, 1, 0.5 }, { 0.5, 1, 0.5 },
	};
	g_mesh.appendColorsRgb(&colors[0], sizeof(colors) / sizeof(colors[0]));


	// 頂点に番号を割り振る--------------------------------------------------------
	uint32_t indices[] = {
		0, 1, 2,
		3, 4, 5,

		6, 7, 8,
		9, 10, 11,

		12, 13, 14,
		15, 16, 17,

		18, 19, 20,
		21, 22, 23,

		24, 25, 26,
		27, 28, 29,

		30, 31, 32,
		33, 34, 35,
	};
	g_mesh.appendIndices(&indices[0], sizeof(indices) / sizeof(indices[0]));


	// 頂点の法線をCinderに計算してもらう
	g_mesh.recalculateNormals();

	// 変数の初期値入力--------------------------------------------------------
	size = Vec2f(100.0f, 100.0f);
}

void Ground::draw(){
	// 土台の情報と表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::scale(size.x, 5.0f, size.y);
	gl::rotate(Vec3f(0.0f, 0.0f, 0.0f));
	gl::draw(g_mesh);	// ポリゴンを描画
	gl::popModelView();  // ここまで-------------------------------------
}
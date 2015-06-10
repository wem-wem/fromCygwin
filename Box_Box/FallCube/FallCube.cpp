#include "FallCube.h"

FallCube::FallCube(){
#pragma region 頂点座標
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
	c_mesh.appendVertices(&vertices[0], sizeof(vertices) / sizeof(vertices[0]));

	// 影の表示は一面だけで良いので別に用意
	Vec3f shadow_vertices[] = {
		{ -1, 1, -1 }, { -1, 1, 1 }, { 1, 1, 1 },
		{ -1, 1, -1 }, { 1, 1, 1 }, { 1, 1, -1 },
	};
	shadow_mesh.appendVertices(&shadow_vertices[0], sizeof(shadow_vertices) / sizeof(shadow_vertices[0]));
#pragma endregion

#pragma region 色指定
	// 頂点毎(面)の色を指定(プレイヤー)--------------------------------------------------------
	Color colors[] = {
		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },
		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },

		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },
		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },

		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },
		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },

		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },
		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },

		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },
		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },

		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },
		{ 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f }, { 1, 0.5f, 0.5f },
	};
	c_mesh.appendColorsRgb(&colors[0], sizeof(colors) / sizeof(colors[0]));

	// 影の色
	Color shadow_colors[] = {
		{ 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
		{ 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
	};
	shadow_mesh.appendColorsRgb(&shadow_colors[0], sizeof(shadow_colors) / sizeof(shadow_colors[0]));
#pragma endregion

#pragma region 頂点番号
	// 頂点に番号を割り振る--------------------------------------------------------
	uint32_t box_indices[] = {
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
	c_mesh.appendIndices(&box_indices[0], sizeof(box_indices) / sizeof(box_indices[0]));

	// 影の頂点番号
	uint32_t shadow_indices[] = {
		0, 1, 2,
		3, 4, 5,
	};
	shadow_mesh.appendIndices(&shadow_indices[0], sizeof(shadow_indices) / sizeof(shadow_indices[0]));
#pragma endregion

	c_mesh.recalculateNormals();
	Rand::randomize();

	gravity = 0.5f;

	for (int i = 0; i < 10; i++){
		cube.push_back({ c_mesh, shadow_mesh, Vec3f(randFloat(-90.0f, 90.0f), randFloat(300.0f, 600.0f), randFloat(-90.0f, 90.0f)), Vec3f(10.0f, 10.0f, 10.0f), 0.0f });
	}
}


#pragma region 更新処理
void FallCube::update(){
	for (auto& CUBE : cube){
		// キューブの落下
		if (CUBE.pos.y > 15.0f){
			CUBE.pos.y -= gravity;
		}
		// ground に着いたら別の場所に再配置
		else{
			CUBE.pos = Vec3f(randFloat(-90.0f, 90.0f), randFloat(300.0f, 600.0f), randFloat(-90.0f, 90.0f));
		}

		// 影の大きさを制御
		if (CUBE.pos.y < 300.0f && CUBE.pos.y > 15.0f) {
			CUBE.shadow_width += 10.0f / (285.0f * 2.0f);
		}
		else if (CUBE.pos.y < 15.0f){
			CUBE.shadow_width = 0.0f;
		}
	}
}
#pragma endregion


#pragma region 描画処理
void FallCube::draw(){
	for (auto CUBE : cube){
		auto pos = CUBE.pos;
		auto mesh = CUBE.cube_mesh;
		auto shadow_mesh = CUBE.cs_mesh;
		auto WIDTH = CUBE.shadow_width;

		// キューブの情報と表示
		gl::pushModelView(); // ここから-------------------------------------
		gl::translate(pos.x, pos.y, pos.z);
		gl::scale(CUBE.size.x, CUBE.size.y, CUBE.size.z);
		gl::rotate(Vec3f(0.0f, 0.0f, 0.0f));
		gl::draw(mesh);	// ポリゴンを描画
		gl::popModelView();  // ここまで-------------------------------------

		// 影の情報と表示
		gl::pushModelView(); // ここから-------------------------------------
		gl::translate(pos.x, 5.0f, pos.z);
		gl::scale(WIDTH, 1.0f, WIDTH);
		gl::rotate(Vec3f(0.0f, 0.0f, 0.0f));
		gl::draw(shadow_mesh);	// ポリゴンを描画
		gl::popModelView();  // ここまで-------------------------------------
	}
}
#pragma endregion

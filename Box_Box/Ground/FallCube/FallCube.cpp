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

	gravity = 0.5f;

	for (int x = 0; x < 2; x++){
		for (int z = 0; z < 1; z++){
			float pos_x = -45;
			float pos_z = -45;
			cube.push_back({ c_mesh, shadow_mesh, Vec3f(pos_x + 20 * x, randFloat(100.0f, 1000.0f), pos_z + 20 * z), Vec3f(10.0f, 10.0f, 10.0f), 0.0f, Color(1, 0, 0), 0 });
		}
	}
}


#pragma region 更新処理
void FallCube::update(){
	for (auto& CUBE : cube){
		// キューブの落下
		if (CUBE.pos.y > 15.0f + ((CUBE.size.y * 2)*CUBE.steps)){
			CUBE.flash_color.g += 0.1;
			CUBE.flash_color.b += 0.1;
			CUBE.pos.y -= gravity;
		}
		// ground に着いたら停止
		else{
			CUBE.pos.y = 15.0f;
		}


		// 影の大きさを制御
		if (CUBE.pos.y < 300.0f + ((CUBE.size.y * 2)*CUBE.steps) && CUBE.pos.y > 15.0f + ((CUBE.size.y * 2)*CUBE.steps)) {
			CUBE.shadow_width += 10.0f / (285.0f * 2.0f);
		}
		else if (CUBE.pos.y == 15.0f + ((CUBE.size.y * 2)*CUBE.steps)){
			CUBE.shadow_width = 10;
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
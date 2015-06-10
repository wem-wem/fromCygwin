#include "Item.h"

Item::Item(){
#pragma region 通常アイテム
#pragma region 頂点座標
	// 立方体の頂点座標を指定--------------------------------------------------------
	Vec3f vertices[] = {
		{ -1, -1, -1 }, { 1, 1, -1 }, { 1, -1, -1 },
		{ -1, -1, -1 }, { -1, 1, -1 }, { 1, 1, -1 },

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
	i_mesh.appendVertices(&vertices[0], sizeof(vertices) / sizeof(vertices[0]));

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
		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },
		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },

		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },
		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },

		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },
		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },

		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },
		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },

		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },
		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },

		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },
		{ 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f }, { 0.5f, 0.5f, 1.0f },
	};
	i_mesh.appendColorsRgb(&colors[0], sizeof(colors) / sizeof(colors[0]));

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
	i_mesh.appendIndices(&box_indices[0], sizeof(box_indices) / sizeof(box_indices[0]));

	// 影の頂点番号
	uint32_t shadow_indices[] = {
		0, 1, 2,
		3, 4, 5,
	};
	shadow_mesh.appendIndices(&shadow_indices[0], sizeof(shadow_indices) / sizeof(shadow_indices[0]));
#pragma endregion
#pragma endregion

	i_mesh.recalculateNormals();
	Rand::randomize();

	for (int i = 0; i < 10; i++){
		obj.push_back({ i_mesh, shadow_mesh, Vec3f(randFloat(-90.0f, 90.0f), randFloat(20.0f, 50.0f), randFloat(-90.0f, 90.0f)), Vec3f(5.0f, 5.0f, 5.0f), 5.0f, false });
	}

	rotate = Vec3f(0.0f, 0.0f, 0.0f);
}


#pragma region 更新処理
void Item::update(){
	rotate += Vec3f(0.5f, 0.5f, 0.0f);

	// アイテムの取得判定がされた場合、即座に別の場所へ再配置
	for (unsigned int i = 0; i < obj.size(); i++)
	{
		if (obj[i].get_flag)
		{
			obj[i].pos = Vec3f(randFloat(-90.0f, 90.0f), randFloat(20.0f, 50.0f), randFloat(-90.0f, 90.0f));
			obj[i].get_flag = false;
		}
	}
}
#pragma endregion

#pragma region 描画処理
void Item::draw(){
	for (auto ITEM : obj){
		auto pos = ITEM.pos;
		auto mesh = ITEM.item_mesh;
		auto shadow_mesh = ITEM.is_mesh;
		auto WIDTH = ITEM.shadow_width;

		// キューブの情報と表示
		gl::pushModelView(); // ここから-------------------------------------
		gl::translate(pos.x, pos.y, pos.z);
		gl::scale(ITEM.size.x, ITEM.size.y, ITEM.size.z);
		gl::rotate(Vec3f(45.0f, 45.0f, 0.0f) + rotate);
		gl::draw(mesh);	// ポリゴンを描画
		gl::popModelView();  // ここまで-------------------------------------

		// 影の情報と表示
		gl::pushModelView(); // ここから-------------------------------------
		gl::translate(pos.x, 5.0f, pos.z);
		gl::scale(WIDTH, 1.0f, WIDTH);
		gl::rotate(Vec3f(0.0f, 45.0f + rotate.y, 0.0f));
		gl::draw(shadow_mesh);	// ポリゴンを描画
		gl::popModelView();  // ここまで-------------------------------------
	}
}
#pragma endregion
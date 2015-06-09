#include "Title.h"

Title::Title(){
#pragma region 立方体の頂点座標を指定
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
	title_mesh.appendVertices(&vertices[0], sizeof(vertices) / sizeof(vertices[0]));
#pragma endregion

#pragma region 頂点毎(面)の色を指定(プレイヤー)
	Color colors[] = {
		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },
		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },

		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },
		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },

		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },
		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },

		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },
		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },

		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },
		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },

		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },
		{ 1, 1, 1 }, { 1, 1, 1 }, { 1, 1, 1 },
	};
	title_mesh.appendColorsRgb(&colors[0], sizeof(colors) / sizeof(colors[0]));
#pragma endregion

#pragma region 頂点に番号を割り振る
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
	title_mesh.appendIndices(&box_indices[0], sizeof(box_indices) / sizeof(box_indices[0]));
#pragma endregion

	title_mesh.recalculateNormals();


	rogo_z = Vec3f(0, 0, 0);

#pragma region 各ボックスの表示座標
	for (int i = 0; i <= 52; i ++){
		// B
		string_cube[0] = { title_mesh, Vec3f(-230.0f, 0.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[1] = { title_mesh, Vec3f(-210.0f, 0.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[2] = { title_mesh, Vec3f(-190.0f, 0.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[3] = { title_mesh, Vec3f(-230.0f, 20.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[4] = { title_mesh, Vec3f(-180.0f, 20.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[5] = { title_mesh, Vec3f(-230.0f, 40.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[6] = { title_mesh, Vec3f(-210.0f, 40.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[7] = { title_mesh, Vec3f(-190.0f, 40.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[8] = { title_mesh, Vec3f(-230.0f, 60.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[9] = { title_mesh, Vec3f(-190.0f, 60.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[10] = { title_mesh, Vec3f(-230.0f, 80.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[11] = { title_mesh, Vec3f(-210.0f, 80.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[12] = { title_mesh, Vec3f(-190.0f, 80.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };

		// o
		string_cube[13] = { title_mesh, Vec3f(-150.0f, 0.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[14] = { title_mesh, Vec3f(-130.0f, 0.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[15] = { title_mesh, Vec3f(-110.0f, 0.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[16] = { title_mesh, Vec3f(-150.0f, 20.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[17] = { title_mesh, Vec3f(-110.0f, 20.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[18] = { title_mesh, Vec3f(-150.0f, 40.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[19] = { title_mesh, Vec3f(-130.0f, 40.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[20] = { title_mesh, Vec3f(-110.0f, 40.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };

		// x
		string_cube[21] = { title_mesh, Vec3f(-70.0f, 0.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[22] = { title_mesh, Vec3f(-30.0f, 0.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[23] = { title_mesh, Vec3f(-50.0f, 20.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[24] = { title_mesh, Vec3f(-70.0f, 40.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[25] = { title_mesh, Vec3f(-30.0f, 40.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };

		// B
		string_cube[26] = { title_mesh, Vec3f(30.0f, 0.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[27] = { title_mesh, Vec3f(50.0f, 0.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[28] = { title_mesh, Vec3f(70.0f, 0.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[29] = { title_mesh, Vec3f(30.0f, 20.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[30] = { title_mesh, Vec3f(80.0f, 20.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[31] = { title_mesh, Vec3f(30.0f, 40.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[32] = { title_mesh, Vec3f(50.0f, 40.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[33] = { title_mesh, Vec3f(70.0f, 40.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[34] = { title_mesh, Vec3f(30.0f, 60.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[35] = { title_mesh, Vec3f(70.0f, 60.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[36] = { title_mesh, Vec3f(30.0f, 80.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[37] = { title_mesh, Vec3f(50.0f, 80.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[38] = { title_mesh, Vec3f(70.0f, 80.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };

		// o
		string_cube[39] = { title_mesh, Vec3f(110.0f, 0.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[40] = { title_mesh, Vec3f(130.0f, 0.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[41] = { title_mesh, Vec3f(150.0f, 0.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[42] = { title_mesh, Vec3f(110.0f, 20.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[43] = { title_mesh, Vec3f(150.0f, 20.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[44] = { title_mesh, Vec3f(110.0f, 40.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[45] = { title_mesh, Vec3f(130.0f, 40.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[46] = { title_mesh, Vec3f(150.0f, 40.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };

		// x
		string_cube[47] = { title_mesh, Vec3f(190.0f, 0.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[48] = { title_mesh, Vec3f(230.0f, 0.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[49] = { title_mesh, Vec3f(210.0f, 20.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[50] = { title_mesh, Vec3f(190.0f, 40.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
		string_cube[51] = { title_mesh, Vec3f(230.0f, 40.0f, -100.0f), Vec3f(10.0f, 10.0f, 10.0f), false };
	}

	text_alpha = 0;
	text_color = ColorA(1, 1, 1, 0);
#pragma endregion
}

#pragma region フォントの読み込みだけmainで実行してもらう
void Title::setup(){
	font = Font(loadAsset("font/MyComSquare-Medium.otf"),40);
}
#pragma endregion

#pragma region 更新処理
void Title::update(){
	for (int i = 0; i < 52; i++){
		if (rogo_z.z < 100){
			rogo_z += Vec3f(0, 0.005f, 0.01f);
		}
		else if (rogo_z.z == 100){
			rogo_z = Vec3f(0, 50.0f, 100.0f);
		}
	}



	text_alpha += 0.05f;

}
#pragma endregion


#pragma region 表示処理
void Title::draw(){
	for (int i = 0; i < 52; i++){
		// キューブの情報と表示
		gl::pushModelView(); // ここから-------------------------------------
		gl::translate(Vec3f(string_cube[i].pos.x, string_cube[i].pos.y, string_cube[i].pos.z) + rogo_z);
		gl::scale(string_cube[i].size.x, string_cube[i].size.y, string_cube[i].size.z);
		gl::rotate(Vec3f(0.0f, 0.0f, 0.0f));
		gl::draw(string_cube[i].cube_mesh);	// ポリゴンを描画
		gl::popModelView();  // ここまで-------------------------------------

		gl::pushModelView(); // ここから-------------------------------------
		gl::rotate(Vec3f(160, 0, 0));
		gl::drawStringCentered(
			"START PUSH [ENTER]",
			Vec2f(0, 100), text_color + std::abs(std::sin(text_alpha)), font);
		gl::popModelView();  // ここまで-------------------------------------

	}
}
#pragma endregion
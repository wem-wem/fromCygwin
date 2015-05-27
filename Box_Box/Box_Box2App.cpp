#include "common.h"


void Box_Box2App::setup()
{
	// 立方体の頂点座標を指定--------------------------------------------------------
	Vec3f box_vertices[] = {
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
	ground_mesh.appendVertices(&box_vertices[0], sizeof(box_vertices) / sizeof(box_vertices[0]));
	player_mesh.appendVertices(&box_vertices[0], sizeof(box_vertices) / sizeof(box_vertices[0]));

	// 影の表示は一面だけで良いので別に用意
	Vec3f shadow_vertices[] = {
		{ -1, 1, -1 }, { -1, 1, 1 }, { 1, 1, 1 },
		{ -1, 1, -1 }, { 1, 1, 1 }, { 1, 1, -1 },
	};
	shadow_mesh.appendVertices(&shadow_vertices[0], sizeof(shadow_vertices) / sizeof(shadow_vertices[0]));


	// 頂点毎(面)の色を指定(土台)--------------------------------------------------------
	Color ground_colors[] = {
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
	ground_mesh.appendColorsRgb(&ground_colors[0], sizeof(ground_colors) / sizeof(ground_colors[0]));

	// 頂点毎(面)の色を指定(プレイヤー)--------------------------------------------------------
	Color player_colors[] = {
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
	player_mesh.appendColorsRgb(&player_colors[0], sizeof(player_colors) / sizeof(player_colors[0]));

	// 影の色
	Color shadow_colors[] = {
		{ 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
		{ 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 },
	};
	shadow_mesh.appendColorsRgb(&shadow_colors[0], sizeof(shadow_colors) / sizeof(shadow_colors[0]));


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
	ground_mesh.appendIndices(&box_indices[0], sizeof(box_indices) / sizeof(box_indices[0]));
	player_mesh.appendIndices(&box_indices[0], sizeof(box_indices) / sizeof(box_indices[0]));

	// 影の頂点番号
	uint32_t shadow_indices[] = {
		0, 1, 2,
		3, 4, 5,
	};
	shadow_mesh.appendIndices(&shadow_indices[0], sizeof(shadow_indices) / sizeof(shadow_indices[0]));

	// 頂点の法線をCinderに計算してもらう
	ground_mesh.recalculateNormals();
	player_mesh.recalculateNormals();


	// ライトの準備--------------------------------------------------------
	// 平行光源を１つ用意
	light = std::unique_ptr<gl::Light>(new gl::Light(gl::Light::DIRECTIONAL, 0));
	light->setAmbient(Color(0.0, 0.0, 0.0));
	light->setDiffuse(Color(1.0, 1.0, 1.0));
	light->setDirection(Vec3f(0.0, 1.0, 1.0)); // 光は真上から真下を照らす


	// カメラの準備--------------------------------------------------------
	camera = CameraPersp(getWindowWidth(), getWindowHeight(),
		35.0, 200.0, 1000.0);

	camera.lookAt(Vec3f(0.0, 300.0, 300.0), // Z軸700の地点から
		Vec3f(0.0, 0.0, 0.0));	// (0, 0, 0)の地点を見るカメラ


	// 変数の初期値入力--------------------------------------------------------
	ground_size = Vec2f(100.0f, 100.0f);

	ry = 45.0f; // Ｙ軸45度傾ける
	player_pos = Vec3f(0, 15, 0); // プレイヤーの初期位置
	gravity = 0.0f;
	a = s = d = w = space = false;
	isjumping = false;



	// カリングON(手前の面のみを表示)
	gl::enable(GL_CULL_FACE);

	// 頂点カラーを対象にしてライティングの計算を行う
	gl::enable(GL_COLOR_MATERIAL);

	// ライティングON
	gl::enable(GL_LIGHTING);

	// 法線を正規化する
	gl::enable(GL_NORMALIZE);

	gl::enableDepthRead();
	gl::enableDepthWrite();
}

void Box_Box2App::keyDown(KeyEvent event)
{
	if (event.getCode() == KeyEvent::KEY_a){
		a = true;
	}

	if (event.getCode() == KeyEvent::KEY_d){
		d = true;
	}

	if (event.getCode() == KeyEvent::KEY_w){
		w = true;
	}

	if (event.getCode() == KeyEvent::KEY_s){
		s = true;
	}

	// ジャンプ
	if (event.getCode() == KeyEvent::KEY_SPACE && !isjumping){
		space = true;
		isjumping = true;
	}
}

void Box_Box2App::keyUp(KeyEvent event){
	if (event.getCode() == KeyEvent::KEY_a){
		a = false;
	}

	if (event.getCode() == KeyEvent::KEY_d){
		d = false;
	}


	if (event.getCode() == KeyEvent::KEY_w){
		w = false;
	}

	if (event.getCode() == KeyEvent::KEY_s){
		s = false;
	}

	// ジャンプ
	if (event.getCode() == KeyEvent::KEY_SPACE){
		space = false;
	}
}

void Box_Box2App::update()
{
	if (a){
		player_pos.x += -1.0f; // 左移動
	}
	if (d){
		player_pos.x += 1.0f; // 左移動
	}
	if (w){
		player_pos.z += -1.0f; // 左移動
	}
	if (s){
		player_pos.z += 1.0f; // 左移動
	}

	// ジャンプ時の挙動
	if (space){
		gravity = 10;
	}
	player_pos.y += gravity;
	gravity -= 1.0f;

	// 地面に触れていたら
	if (player_pos.y <= 15.0f){
		gravity = 0;
		player_pos.y = 15.0f;
		isjumping = false;
	}
	else{
		space = false;
	}
}

void Box_Box2App::draw()
{
	// clear out the window with black
	gl::clear(Color(0.2f, 0.2f, 0.2f));
	
	// カメラの状態から行列を作成
	// 視点座標変換用と正規化デバイス座標変換用の２つを用意する
	gl::setMatrices(camera);

	// ライティング開始
	light->enable();

	// 土台の情報と表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::scale(ground_size.x, 5.0f, ground_size.y);
	gl::rotate(Vec3f(0.0f, ry, 0.0f));
	gl::draw(ground_mesh);	// ポリゴンを描画
	gl::popModelView();  // ここまで-------------------------------------

	// 自機の情報と表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::translate(player_pos.x, player_pos.y, player_pos.z);
	gl::scale(10.0f, 10.0f, 10.0f);
	gl::rotate(Vec3f(0.0f, ry, 0.0f));
	gl::draw(player_mesh);	// ポリゴンを描画
	gl::popModelView();  // ここまで-------------------------------------

	// 影の情報と表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::translate(player_pos.x, 5.0f, player_pos.z);
	gl::scale(gravity, 1.0f, gravity);
	gl::rotate(Vec3f(0.0f, ry, 0.0f));
	gl::draw(shadow_mesh);	// ポリゴンを描画
	gl::popModelView();  // ここまで-------------------------------------

	light->disable();
}

CINDER_APP_NATIVE(Box_Box2App, RendererGl)

#include "Player.h"

#pragma region コンストラクタ
Player::Player(){
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
	p_mesh.appendVertices(&vertices[0], sizeof(vertices) / sizeof(vertices[0]));

	// 影の表示は一面だけで良いので別に用意
	Vec3f shadow_vertices[] = {
		{ -1, 1, -1 }, { -1, 1, 1 }, { 1, 1, 1 },
		{ -1, 1, -1 }, { 1, 1, 1 }, { 1, 1, -1 },
	};
	shadow_mesh.appendVertices(&shadow_vertices[0], sizeof(shadow_vertices) / sizeof(shadow_vertices[0]));

	// 頂点毎(面)の色を指定(プレイヤー)--------------------------------------------------------
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
	p_mesh.appendColorsRgb(&colors[0], sizeof(colors) / sizeof(colors[0]));

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
	p_mesh.appendIndices(&box_indices[0], sizeof(box_indices) / sizeof(box_indices[0]));

	// 影の頂点番号
	uint32_t shadow_indices[] = {
		0, 1, 2,
		3, 4, 5,
	};
	shadow_mesh.appendIndices(&shadow_indices[0], sizeof(shadow_indices) / sizeof(shadow_indices[0]));

	p_mesh.recalculateNormals();

	// 変数の初期化
	pos = Vec3f(0, 15, 0);			// プレイヤーの初期位置
	size = Vec3f(8.0f, 8.0f, 8.0f); // プレイヤーの大きさ
	gravity = 0.0f;
	move_speed = 1.0f;
	get_A = get_S = get_D = get_W = get_SPACE = false;
	isjumping = false;
	shadow_size = 8.0f;
}
#pragma endregion


void Player::setup(){
	font = Font(loadAsset("font/MyComSquare-Medium.otf"), 15);
}

#pragma region キーが押された時の判定
void Player::keyDown(KeyEvent event, audio::BufferPlayerNodeRef& JUMP_SE){
	if (event.getCode() == KeyEvent::KEY_a){
		get_A = true;
	}

	if (event.getCode() == KeyEvent::KEY_d){
		get_D = true;
	}

	if (event.getCode() == KeyEvent::KEY_w){
		get_W = true;
	}

	if (event.getCode() == KeyEvent::KEY_s){
		get_S = true;
	}

	// ジャンプ
	if (event.getCode() == KeyEvent::KEY_SPACE && !isjumping){
		JUMP_SE->start();
		get_SPACE = true;
		isjumping = true;
	}
}
#pragma endregion


#pragma region  キーを離した時の判定
void Player::keyUp(KeyEvent event){
	if (event.getCode() == KeyEvent::KEY_a){
		get_A = false;
	}

	if (event.getCode() == KeyEvent::KEY_d){
		get_D = false;
	}

	if (event.getCode() == KeyEvent::KEY_w){
		get_W = false;
	}

	if (event.getCode() == KeyEvent::KEY_s){
		get_S = false;
	}

	// ジャンプ
	if (event.getCode() == KeyEvent::KEY_SPACE){
		get_SPACE = false;
	}
}
#pragma endregion


#pragma region 各クラスのポインタを取得
void Player::SetReference(FallCube* fc_ref, Item* i_ref, GameUI* ui_ref){
	fallcube_ref = fc_ref;
	item_ref = i_ref;
	game_ui_ref = ui_ref;
}
#pragma endregion


#pragma region 自機左面の当たり判定
bool Player::isCollisionFallCube_A(){
	for (unsigned int i = 0; i < fallcube_ref->cube.size(); i++){
		// fallcube の下辺との当たり判定
		if (fallcube_ref->cube[i].pos.y - fallcube_ref->cube[i].size.y < pos.y + size.y &&
			fallcube_ref->cube[i].pos.y + fallcube_ref->cube[i].size.y > pos.y - size.y){

			// fallcube の右面との当たり判定
			if (fallcube_ref->cube[i].pos.x + fallcube_ref->cube[i].size.x + move_speed / 2 > pos.x - size.x &&
				fallcube_ref->cube[i].pos.x + fallcube_ref->cube[i].size.x - move_speed / 2 < pos.x - size.x &&
				fallcube_ref->cube[i].pos.z + fallcube_ref->cube[i].size.z > pos.z - size.z &&
				fallcube_ref->cube[i].pos.z - fallcube_ref->cube[i].size.z < pos.z + size.z)
			{
				return true;
			}

			else
			{
				return false;
			}
		}
	}
	return false;
}
#pragma endregion


#pragma region 自機右面の当たり判定
bool Player::isCollisionFallCube_D(){
	for (unsigned int i = 0; i < fallcube_ref->cube.size(); i++){
		// fallcube の下辺との当たり判定
		if (fallcube_ref->cube[i].pos.y - fallcube_ref->cube[i].size.y < pos.y + size.y &&
			fallcube_ref->cube[i].pos.y + fallcube_ref->cube[i].size.y > pos.y - size.y)
		{
			// fallcube の左面との当たり判定
			if (fallcube_ref->cube[i].pos.x - fallcube_ref->cube[i].size.x - move_speed / 2 < pos.x + size.x &&
				fallcube_ref->cube[i].pos.x - fallcube_ref->cube[i].size.x + move_speed / 2 > pos.x + size.x &&
				fallcube_ref->cube[i].pos.z + fallcube_ref->cube[i].size.z > pos.z - size.z &&
				fallcube_ref->cube[i].pos.z - fallcube_ref->cube[i].size.z < pos.z + size.z)
			{
				return true;
			}

			else
			{
				return false;
			}
		}
	}
	return false;
}
#pragma endregion


#pragma region 自機の奥の面の当たり判定
bool Player::isCollisionFallCube_W(){
	for (unsigned int i = 0; i < fallcube_ref->cube.size(); i++){
		// fallcube の下辺との当たり判定
		if (fallcube_ref->cube[i].pos.y - fallcube_ref->cube[i].size.y < pos.y + size.y &&
			fallcube_ref->cube[i].pos.y + fallcube_ref->cube[i].size.y > pos.y - size.y)
		{
			// fallcube の手前の面との当たり判定
			if (fallcube_ref->cube[i].pos.x + fallcube_ref->cube[i].size.x > pos.x - size.x &&
				fallcube_ref->cube[i].pos.x - fallcube_ref->cube[i].size.x < pos.x + size.x &&
				fallcube_ref->cube[i].pos.z + fallcube_ref->cube[i].size.z + move_speed / 2 > pos.z - size.z &&
				fallcube_ref->cube[i].pos.z - fallcube_ref->cube[i].size.z - move_speed / 2 < pos.z + size.z)
			{
				return true;
			}

			else
			{
				return false;
			}
		}
	}
	return false;
}
#pragma endregion


#pragma region 自機の手前の面の当たり判定
bool Player::isCollisionFallCube_S(){
	for (unsigned int i = 0; i < fallcube_ref->cube.size(); i++){
		// fallcube の下辺との当たり判定
		if (fallcube_ref->cube[i].pos.y - fallcube_ref->cube[i].size.y < pos.y + size.y &&
			fallcube_ref->cube[i].pos.y + fallcube_ref->cube[i].size.y > pos.y - size.y)
		{
			// fallcube の奥の面との当たり判定
			if (fallcube_ref->cube[i].pos.x + fallcube_ref->cube[i].size.x > pos.x - size.x &&
				fallcube_ref->cube[i].pos.x - fallcube_ref->cube[i].size.x < pos.x + size.x &&
				fallcube_ref->cube[i].pos.z + fallcube_ref->cube[i].size.z + move_speed / 2 > pos.z - size.z &&
				fallcube_ref->cube[i].pos.z - fallcube_ref->cube[i].size.z - move_speed / 2 < pos.z + size.z)
			{
				return true;
			}

			else
			{
				return false;
			}
		}
	}
	return false;
}
#pragma endregion


#pragma region 自機の底面の面の当たり判定
bool Player::isCollisionFallCube_SPACE(){
	for (unsigned int i = 0; i < fallcube_ref->cube.size(); i++){
		// fallcube の下辺との当たり判定
		if (fallcube_ref->cube[i].pos.y - fallcube_ref->cube[i].size.y < pos.y + size.y &&
			fallcube_ref->cube[i].pos.y - fallcube_ref->cube[i].size.y - gravity > pos.y + size.y)
		{
			// fallcube の上面との当たり判定
			if (fallcube_ref->cube[i].pos.x + fallcube_ref->cube[i].size.x > pos.x - size.x &&
				fallcube_ref->cube[i].pos.x - fallcube_ref->cube[i].size.x < pos.x + size.x &&
				fallcube_ref->cube[i].pos.z + fallcube_ref->cube[i].size.z + move_speed / 2 > pos.z - size.z &&
				fallcube_ref->cube[i].pos.z - fallcube_ref->cube[i].size.z - move_speed / 2 < pos.z + size.z)
			{
				return true;
			}

			else
			{
				return false;
			}
		}
	}
	return false;
}
#pragma endregion


#pragma region アイテムの取得判定
void Player::isCollisionItem(unsigned int& score, unsigned int& time, audio::BufferPlayerNodeRef& ITEM_GET_SE){
	for (unsigned int i = 0; i < item_ref->obj.size(); i++)
	{
		// アイテムの底辺よりも自機の上辺が高い時
		if (pos.y + size.y >= item_ref->obj[i].pos.y &&
			pos.y - size.y <= item_ref->obj[i].pos.y)
		{
			// 自機の左右両面の間
			if (pos.x + size.x >= item_ref->obj[i].pos.x &&
				pos.x - size.x <= item_ref->obj[i].pos.x)
			{
				// 自機の手前と奥の面の間
				if (pos.z + size.z >= item_ref->obj[i].pos.z &&
					pos.z - size.z <= item_ref->obj[i].pos.z)
				{
					item_ref->obj[i].get_flag = true;
					ITEM_GET_SE->start();
					score += 1;
					time += 30;
				}
			}
		}
	}
}
#pragma endregion


#pragma region 更新処理
void Player::update(unsigned int& score, unsigned int& scene, audio::BufferPlayerNodeRef& ITEM_GET_SE){
	float ground_end = 92.0f;
	isCollisionItem(score, game_ui_ref->_time, ITEM_GET_SE);

	if (get_A){
		if (pos.x > -ground_end){
			pos.x += -move_speed; // 左移動
		}
	}

	if (get_D){
		if (pos.x < ground_end){
			pos.x += move_speed; // 右移動
		}
	}

	if (get_W){
		if (pos.z > -ground_end){
			pos.z += -move_speed; // 奥へ移動
		}
	}

	if (get_S){
		if (pos.z < ground_end){
			pos.z += move_speed; // 手前へ移動
		}
	}

	if (isCollisionFallCube_A() || isCollisionFallCube_D() ||
		isCollisionFallCube_S() || isCollisionFallCube_W() ||
		isCollisionFallCube_SPACE())
	{
		scene = RESULT;

	}


	// ジャンプ時の挙動
	if (get_SPACE){
		gravity = 10;
	}
	pos.y += gravity;
	gravity -= 1.0f;

	// 地面に触れていたら
	if (pos.y <= 15.0f){
		gravity = 0;
		pos.y = 15.0f;
		isjumping = false;
		shadow_size = 8.0f;
	}
	else{
		shadow_size += 8.0f / (2.0f * 2.0f);
		get_SPACE = false;
	}
}
#pragma endregion


#pragma region 描画処理
void Player::draw(){
	// 自機の情報と表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::translate(pos.x, pos.y, pos.z);
	gl::scale(size.x, size.y, size.z);
	gl::rotate(Vec3f(0.0f, 0.0f, 0.0f));
	gl::draw(p_mesh);	// ポリゴンを描画
	gl::popModelView();  // ここまで-------------------------------------

	// 影の情報と表示
	gl::pushModelView(); // ここから-------------------------------------
	gl::translate(pos.x, 5.0f, pos.z);
	gl::scale(gravity, 1.0f, gravity);
	gl::rotate(Vec3f(0.0f, 0.0f, 0.0f));
	gl::draw(shadow_mesh);	// ポリゴンを描画
	gl::popModelView();  // ここまで-------------------------------------
}
#pragma endregion

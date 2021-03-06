#include "Player.h"

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

	pos = Vec3f(0, 15, 0);			// プレイヤーの初期位置
	size = Vec3f(8.0f, 8.0f, 8.0f); // プレイヤーの大きさ
	gravity = 0.0f;
	move_speed = 1.0f;
	get_A = get_S = get_D = get_W = get_SPACE = false;
	isjumping = false;
	shadow_size = 8.0f;
	fallcube_steps = 0;
}

// キーが押された時の判定
void Player::keyDown(KeyEvent event){
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
		get_SPACE = true;
		isjumping = true;
	}
}

// キーを離した時の判定
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


void Player::SetReference(FallCube* ref){
	fallcube_ref = ref;
}


bool Player::isCollision_A(){
	for (int i = 0; i < fallcube_ref->cube.size(); i++){
		// fallcube の下辺との当たり判定
		if (fallcube_ref->cube[i].pos.y - fallcube_ref->cube[i].size.y <= pos.y + size.y &&
			fallcube_ref->cube[i].pos.y + fallcube_ref->cube[i].size.y >= pos.y - size.y){
			// fallcube の右面の当たり判定
			if (fallcube_ref->cube[i].pos.x + fallcube_ref->cube[i].size.x <= pos.x - size.x &&
				fallcube_ref->cube[i].pos.x + fallcube_ref->cube[i].size.x + move_speed >= pos.x - size.x &&
				fallcube_ref->cube[i].pos.z + fallcube_ref->cube[i].size.z >= pos.z - size.z &&
				fallcube_ref->cube[i].pos.z - fallcube_ref->cube[i].size.z <= pos.z + size.z){
				return true;
			}
			else return false;
		}
	}
	return false;
}


bool Player::isCollision_D(){
	for (int i = 0; i < fallcube_ref->cube.size(); i++){
		// fallcube の下辺との当たり判定
		if (fallcube_ref->cube[i].pos.y - fallcube_ref->cube[i].size.y <= pos.y + size.y &&
			fallcube_ref->cube[i].pos.y + fallcube_ref->cube[i].size.y >= pos.y - size.y){
			// fallcube の左面の当たり判定
			if (fallcube_ref->cube[i].pos.x - fallcube_ref->cube[i].size.x >= pos.x + size.x &&
				fallcube_ref->cube[i].pos.x - fallcube_ref->cube[i].size.x - move_speed <= pos.x + size.x &&
				fallcube_ref->cube[i].pos.z + fallcube_ref->cube[i].size.z >= pos.z - size.z &&
				fallcube_ref->cube[i].pos.z - fallcube_ref->cube[i].size.z <= pos.z + size.z){
				return true;
			}
			else return false;
		}
	}
	return false;
}


bool Player::isCollision_W(){
	for (int i = 0; i < fallcube_ref->cube.size(); i++){
		// fallcube の下辺との当たり判定
		if (fallcube_ref->cube[i].pos.y - fallcube_ref->cube[i].size.y <= pos.y + size.y &&
			fallcube_ref->cube[i].pos.y + fallcube_ref->cube[i].size.y >= pos.y - size.y){
			// fallcube の手前の面との当たり判定
			if (fallcube_ref->cube[i].pos.x + fallcube_ref->cube[i].size.x >= pos.x - size.x &&
				fallcube_ref->cube[i].pos.x - fallcube_ref->cube[i].size.x <= pos.x + size.x &&
				fallcube_ref->cube[i].pos.z + fallcube_ref->cube[i].size.z + move_speed >= pos.z - size.z &&
				fallcube_ref->cube[i].pos.z - fallcube_ref->cube[i].size.z <= pos.z + size.z){
				return true;
			}
			else return false;
		}
	}
	return false;
}


bool Player::isCollision_S(){
	for (int i = 0; i < fallcube_ref->cube.size(); i++){
		// fallcube の下辺との当たり判定
		if (fallcube_ref->cube[i].pos.y - fallcube_ref->cube[i].size.y <= pos.y + size.y &&
			fallcube_ref->cube[i].pos.y + fallcube_ref->cube[i].size.y >= pos.y - size.y){
			// fallcube の奥の面との当たり判定
			if (fallcube_ref->cube[i].pos.x + fallcube_ref->cube[i].size.x >= pos.x - size.x &&
				fallcube_ref->cube[i].pos.x - fallcube_ref->cube[i].size.x <= pos.x + size.x &&
				fallcube_ref->cube[i].pos.z + fallcube_ref->cube[i].size.z >= pos.z - size.z &&
				fallcube_ref->cube[i].pos.z - fallcube_ref->cube[i].size.z - move_speed <= pos.z + size.z){
				return true;
			}
			else return false;
		}
	}
	return false;
}


void Player::onCube(){
	for (int i = 0; i < fallcube_ref->cube.size(); i++){
		if (fallcube_ref->cube[i].pos.y + fallcube_ref->cube[i].size.y <= pos.y - size.y){
			if (fallcube_ref->cube[i].pos.x + fallcube_ref->cube[i].size.x >= pos.x - size.x &&
				fallcube_ref->cube[i].pos.x - fallcube_ref->cube[i].size.x <= pos.x + size.x &&
				fallcube_ref->cube[i].pos.z + fallcube_ref->cube[i].size.z >= pos.z - size.z &&
				fallcube_ref->cube[i].pos.z - fallcube_ref->cube[i].size.z <= pos.z + size.z){
				fallcube_ref->cube[i].steps = 1;
				fallcube_steps = /*(fallcube_ref->cube[i].pos.y + fallcube_ref->cube[i].size.y) +*/ ((fallcube_ref->cube[i].size.y * 2) * fallcube_ref->cube[i].steps);
			}
			else {
				fallcube_ref->cube[i].steps = 0;
				fallcube_steps = /*(fallcube_ref->cube[i].pos.y + fallcube_ref->cube[i].size.y) +*/ ((fallcube_ref->cube[i].size.y * 2) * fallcube_ref->cube[i].steps);
			}
		}
	}
}

void Player::update(){
	float ground_end = 92.0f;


	if (!isCollision_A()){
		if (get_A){
			if (pos.x > -ground_end){
				pos.x += -move_speed; // 左移動
			}
		}
	}

	if (!isCollision_D()){
		if (get_D){
			if (pos.x < ground_end){
				pos.x += move_speed; // 右移動
			}
		}
	}

	if (!isCollision_W()){
		if (get_W){
			if (pos.z > -ground_end){
				pos.z += -move_speed; // 奥へ移動
			}
		}
	}

	if (!isCollision_S()){
		if (get_S){
			if (pos.z < ground_end){
				pos.z += move_speed; // 手前へ移動
			}
		}
	}

	// ジャンプ時の挙動
	if (get_SPACE){
		gravity = 10;
	}
	pos.y += gravity;
	gravity -= 1.0f;

	// 地面に触れていたら
	if (pos.y <= 15.0f + fallcube_steps){
		gravity = 0;
		pos.y = 15.0f + fallcube_steps;
		isjumping = false;
		shadow_size = 8.0f;
	}
	else{
		shadow_size += 8.0f / (2.0f * 2.0f);
		get_SPACE = false;
	}
}


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
	gl::translate(pos.x, 5.0f + fallcube_steps, pos.z);
	gl::scale(gravity, 1.0f, gravity);
	gl::rotate(Vec3f(0.0f, 0.0f, 0.0f));
	gl::draw(shadow_mesh);	// ポリゴンを描画
	gl::popModelView();  // ここまで-------------------------------------
}
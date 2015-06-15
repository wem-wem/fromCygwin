#include "../common.h" 
#include "../Object/Object.h"
#include "../Bullet/Bullet.h"


class Player;
typedef std::shared_ptr<Player> PlayerSP;

std::list<Bullet_obj>b_obj;

class Player : public Object{
private:
	float rx, ry;
	Vec2f speed;
	Vec2f pos;

	bool get_w, get_a, get_s, get_d;
	bool getKey_space;

	gl::Texture player_image;


public:
	Player();
	~Player(){};

	void keyDown(KeyEvent event);
	void keyUp(KeyEvent event);
	void CreateBullet();
	void update();
	void draw();
};
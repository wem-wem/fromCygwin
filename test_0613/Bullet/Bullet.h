#include "../common.h" 
#include "../Object/Object.h"
#include "../Player/Player.h"


class Bullet;
typedef std::shared_ptr<Bullet> BulletSP;

struct B_Obj{
	Vec2f pos;
	Vec2f speed;
	bool isShot;
};

class Bullet : public Object{
private:
	Vec2f _speed;
	Vec2f _pos;
	bool _getKey_space;
	std::list<B_Obj> obj;

	gl::Texture bullet_image;

public:
	Bullet();
	~Bullet(){};

	void setup();
	void keyDown(KeyEvent event);
	void keyUp(KeyEvent event);
	void update();
	void draw();
};
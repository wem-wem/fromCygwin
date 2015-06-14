#include "../common.h" 
#include "../Object/Object.h"

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
	std::list<B_Obj> obj;

	gl::Texture bullet_image;

public:
	Bullet();
	~Bullet(){};

	void setup();
	void update();
	void draw();
};
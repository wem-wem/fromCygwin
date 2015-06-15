#include "../common.h" 
#include "../Object/Object.h"


class Bullet;
typedef std::shared_ptr<Bullet> BulletSP;

// ’e‚É•K—v‚Èî•ñ
struct Bullet_obj{
	Vec2f speed;
	Vec2f pos;
	bool getKey_space;
};

class Bullet : public Object{
private:
	Bullet_obj obj;

	gl::Texture bullet_image;

public:
	Bullet();
	~Bullet(){};

	void keyDown(KeyEvent event);
	void keyUp(KeyEvent event);
	void update();
	void draw();
};
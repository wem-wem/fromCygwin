#include "../common.h" 


class Bullet;
typedef std::shared_ptr<Bullet> BulletSP;

// ’e‚É•K—v‚Èî•ñ
class Bullet{
private:
	Vec2f speed;
	Vec2f pos;
	gl::Texture bullet_image;

public:
	Bullet();
	~Bullet(){};

	void keyDown(KeyEvent event);
	void keyUp(KeyEvent event);
	void update();
	void draw();
};
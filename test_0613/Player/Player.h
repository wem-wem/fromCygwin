#include "../common.h" 
#include "../Object/Object.h"


class Player;
typedef std::shared_ptr<Player> PlayerSP;

class Player : public Object{
private:
	float _rx, _ry;
	Vec2f _speed;
	Vec2f _pos;

	bool _get_w, _get_a, _get_s, _get_d;
	bool _get_space;

	gl::Texture player_image;


public:
	Player();
	~Player(){};

	void setup();
	void keyDown(KeyEvent event);
	void keyUp(KeyEvent event);
	void update();
	void draw();
};
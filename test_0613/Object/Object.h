#include "../common.h" 

class Object;
typedef std::shared_ptr<Object> ObjectSP;

class Object{
public:
	float _rx, _ry;
	float _speed;
	Vec2f _pos;
	
	Object();
	~Object(){};

	virtual void setup() = 0;
	virtual void update() = 0;
	virtual void draw() = 0;
};
#include "../common.h" 

class Object;
typedef std::shared_ptr<Object> ObjectSP;

class Object{
public:
	float rx, ry;
	float speed;
	Vec2f pos;

	gl::Texture image;
	
	Object();
	~Object(){};

	virtual void update() = 0;
	virtual void draw() = 0;
};
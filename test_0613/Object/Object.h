#include "../common.h" 

class Object;
typedef std::shared_ptr<Object> ObjectSP;


class Object{
public:
	float rx, ry;
	float speed;
	Vec3f pos;
	
	Object();
	~Object(){};

	void setup();
	virtual void update() = 0;
	virtual void draw() = 0;
};
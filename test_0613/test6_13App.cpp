#include "common.h"
#include "Player/Player.h"
#include "Bullet/Bullet.h"

class test6_13App : public AppNative {
private:
	PlayerSP player = PlayerSP(new Player());
	BulletSP bullet = BulletSP(new Bullet());

public:
	void setup();
	void mouseDown( MouseEvent event );	
	void keyDown(KeyEvent event);
	void keyUp(KeyEvent event);
	void update();
	void draw();
};

void test6_13App::setup()
{
	player->setup();
	bullet->setup();
}

void test6_13App::mouseDown( MouseEvent event )
{
}


void test6_13App::keyDown(KeyEvent event){
	player->keyDown(event);
	bullet->keyDown(event);
}


void test6_13App::keyUp(KeyEvent event){
	player->keyUp(event);
	bullet->keyUp(event);
}


void test6_13App::update()
{
	player->update();
	bullet->update();
}

void test6_13App::draw()
{
	gl::clear(Color(0.2f, 0.2f, 0.2f));

	player->draw();

	bullet->draw();
}

CINDER_APP_NATIVE( test6_13App, RendererGl )

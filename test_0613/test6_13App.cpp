#include "common.h"
#include "Player/Player.h"

class test6_13App : public AppNative {
	PlayerSP player = PlayerSP(new Player());

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
}

void test6_13App::mouseDown( MouseEvent event )
{
}


void test6_13App::keyDown(KeyEvent event){
	player->keyDown(event);
}


void test6_13App::keyUp(KeyEvent event){
	player->keyUp(event);
}


void test6_13App::update()
{
	player->update();
}

void test6_13App::draw()
{
	gl::clear(Color(0.2f, 0.2f, 0.2f));

	player->draw();
}

CINDER_APP_NATIVE( test6_13App, RendererGl )

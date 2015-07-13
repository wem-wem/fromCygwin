#include "common.h"
#include <iostream>

typedef std::chrono::time_point<std::chrono::system_clock,
								std::chrono::system_clock::duration> time_point;

struct Object
{
	Vec3f pos;
	int timer;
	bool isvanish;
};


class Game_SeptemberApp : public AppNative 
{
private:
	time_point m_start;
	time_point m_now;
	Vec3f rotate;
	std::list<Object> objs;

public:
	void setup();
	void update();
	void draw();

	// �}���`�^�b�`��L���ɂ���
	void prepareSettings(Settings* settings) override
	{
		settings->enableMultiTouch();
	}

	// �ȉ��A�^�b�`����ŌĂяo����郁���o�֐�
	// �^�b�`�J�n����
	void touchesBegan(TouchEvent event);
};

void Game_SeptemberApp::setup()
{
	m_start = std::chrono::system_clock::now();
}


void Game_SeptemberApp::touchesBegan(TouchEvent event)
{
	// �^�b�`��������擾
	// �}���`�^�b�`�̎��͕����̃^�b�`��񂪊i�[���ꂤ��
	const std::vector<TouchEvent::Touch>& touches = event.getTouches();

	for (const TouchEvent::Touch& touch : touches) 
	{
		// �^�b�`�ʒu
		// Widnow: �A�v����ʍ��オ(0, 0)�̍��W
		// OSX: �g���b�N�p�b�h�̍��オ(0, 0)�ŁA�E�����A�v����ʂ̉E���̍��W
		Vec2f touch_pos = touch.getPos();
		objs.push_back({ Vec3f(touch_pos, 0), 0, false });

		// ���O�̈ʒu���擾�ł���
		Vec2f touch_prev_pos = touch.getPrevPos();

		// �����^�b�`���������鎯�ʎq
		uint32_t touch_id = touch.getId();

		// �^�b�`����̎���
		double touch_time = touch.getTime();
	}
}


void Game_SeptemberApp::update()
{
	m_now = std::chrono::system_clock::now();
	auto count = m_now - m_start;
	int sec;
	sec = std::chrono::duration_cast<std::chrono::milliseconds>(count).count() % 60;
	//std::cout << sec << std::endl;
	rotate += Vec3f(sec / 2, sec, 0);

	for (auto& obj : objs)
	{
		if (!obj.isvanish)
		{
			obj.timer++;
		}
		
		if (obj.timer > 120)
		{
			obj.isvanish = true;
		}
	}

	std::list<Object>::iterator it = objs.begin();
	while (it != objs.end())
	{
		if (it->isvanish)
		{
			it = objs.erase(it);
			continue;
		}
		it++;
	}
}

void Game_SeptemberApp::draw()
{
	// clear out the window with black
	gl::clear(Color(0, 0, 0));

	for (auto obj : objs)
	{
		gl::rotate(Vec3f(rotate));
		gl::drawSphere(obj.pos, 10, 64);
	}
}

CINDER_APP_NATIVE(Game_SeptemberApp, RendererGl)

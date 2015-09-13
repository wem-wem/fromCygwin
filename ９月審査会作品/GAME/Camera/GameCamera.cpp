#include "GameCamera.h"

GameCamera::GameCamera(){
	player = PlayerSP(new Player);
	angle_ = 0.f;
	camera_angle_max = 0.3f;
}


void GameCamera::setup()
{
	const auto& window = getWindowSize();
	const float fov = 35.0f;
	const float nearPlane = 0.1f;
	const float farPlane = 100.0f;

	camera = new CameraPersp(window.x, window.y,
							 fov, nearPlane, farPlane);

	// Vec3f(0.0, 0.0, 7.0) = Vec3f::zAxis() * 7.0;
	camera->lookAt(Vec3f::zAxis() * 7.f,
				   Vec3f::zero());

	//// Žg‚¢•û‚ª‚í‚©‚ç‚Ê‚¡
	//camera->getProjectionMatrix();
}


GameCamera::~GameCamera()
{
	delete camera;
}

void GameCamera::update()
{
	Quatf orientation = Quatf(Vec3f::yAxis(), angle_);
	camera->setOrientation(orientation);
}


void GameCamera::target_update(Vec2i direction)
{
	if (direction.x == LEFT && angle_ < camera_angle_max)
	{
		angle_ += 0.002f;
	}

	if (direction.x == RIGHT && angle_ > -camera_angle_max)
	{
		angle_ -= 0.002f;
	}
}


void GameCamera::SetCamera()
{
	gl::setMatrices(*camera);
}



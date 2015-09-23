#include "Particle.h"

Particle::Particle(){
	clear_time = 0;
	is_ready = false;

	for (int i = 0; i < PARTICLE_MAX; ++i)
	{
		pos[i] = Vec3f::zero();
		size[i] = Vec3f::zero();
		speed[i] = Vec3f::zero();
		color[i] = { 0, 0, 0, 1 };
	}
}


void Particle::splitCubeInit(Vec3f particle_pos)
{
	if (!is_ready)
	{
		for (int i = 0; i < PARTICLE_MAX; ++i)
		{
			pos[i] = particle_pos;
			size[i] = { 0.3f, 0.3f, 0.3f };
			speed[i] = {
				Rand::randFloat(-5.f, 5.f),
				Rand::randFloat(-5.f, 5.f),
				Rand::randFloat(-5.f, 5.f)
			};
			color[i] = {
				Rand::randFloat(0, 1),
				Rand::randFloat(0, 1),
				Rand::randFloat(0, 1),
			};
		}
		is_ready = true;
	}
}


void Particle::splitCubeDraw()
{
	if (is_ready)
	{
		if (clear_time <= 60)
		{
			for (int i = 0; i < PARTICLE_MAX; ++i)
			{
				gl::color(color[i]);
				gl::drawCube(pos[i], size[i]);
				gl::color(1, 1, 1);

				pos[i] += speed[i];
				if (color[i].a >= 0)
				{
					color[i].a -= 0.02f;
				}
			}
			clear_time++;
		}

		else
		{
			clear_time = 0;
			is_ready = false;
		}
	}
}

#pragma once
#include "cinder/app/AppNative.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/Material.h"
#include "cinder/gl/Light.h"
#include "cinder/ImageIo.h"
#include "cinder/Camera.h"
#include "cinder/ObjLoader.h"
#include "cinder/TriMesh.h"
#include "cinder/rand.h"

using namespace ci;
using namespace ci::app;


// ‰æ–Ê‘€ì‚Ì•ûŒü‚É”Ô†‚ğU‚é
enum Direction
{
	LEFT = 0,
	RIGHT = 1,
	UP = 2,
	DOWN = 3,
	DEFAULT = 4,
};

#pragma once

#include "cinder/app/AppNative.h"
#include "cinder/TriMesh.h"
#include "cinder/Camera.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Light.h"
#include "cinder/Font.h"

using namespace ci;
using namespace ci::app;
using namespace std;


// シーン切り替え用
enum{
	TITLE,
	GAME,
	RESULT
};

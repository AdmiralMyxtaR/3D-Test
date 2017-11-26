#pragma once
class Graphics;
class ScreenSpaceTransformer;
class VerticeList;
#include "Vector3.h"
namespace globals
{
	extern Graphics* graphics;
	extern ScreenSpaceTransformer* sst;
	extern Vector3* cameraPos;
	extern Vector3* cameraAngle;
	extern VerticeList* verticeList;
	extern double* fov;
}
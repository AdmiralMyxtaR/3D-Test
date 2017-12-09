#pragma once
class Graphics;
class ScreenSpaceTransformer;
class VerticeList;
struct Matrix3;
#include "Vector3.h"
#include "Matrix3.h"
namespace globals
{
	extern Graphics* graphics;
	extern ScreenSpaceTransformer* sst;
	extern Vector3* cameraPos;
	extern Vector3* cameraAngle;
	extern VerticeList* verticeList;
	extern Matrix3* rotationMatrix;
	extern double* fov;
}
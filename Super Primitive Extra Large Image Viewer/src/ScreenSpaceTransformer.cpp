#include "ScreenSpaceTransformer.h"
#include "globals.h"
#include "Graphics.h"
ScreenSpaceTransformer::ScreenSpaceTransformer(Vector2 & dims)
{
	this->dims = dims;
}

Vector2 ScreenSpaceTransformer::getPixelLocation(Vector3 & transformedVec)
{
	Vector3 arg(transformedVec);
	arg.x /= arg.z; //-= *globals::cameraPos;
	arg.y /= arg.z;
	arg.y = -arg.y;
	arg.x += 1;
	arg.y += 1;
	return Vector2(arg)*globals::graphics->getScreenHeight();
}

std::pair<Vector2, Vector2> ScreenSpaceTransformer::getPixelLocation(Vector3 & v1, Vector3 & v2)
{
	Vector3 camPos = *globals::cameraPos;
	Vector3 camDist1 = camPos - v1;
	Vector3 camDist2 = camPos - v2;
	Vector2 span = camDist2 - camDist1;
	span = span / v1.z;
	camDist1.x += 1;
	camDist1.y = -camDist1.y;
	camDist1.y += 1;
	Vector2 screenPos1 = camDist1*dims.y*0.5;
	camDist2 = camDist1 + Vector3(span.x, span.y, 0) / v1.z;
	camDist2.x += 1;
	camDist2.y = -camDist1.y;
	camDist2.y += 1;
	Vector2 screenPos2 = camDist2*dims.y*0.5;
	return{ screenPos1,screenPos2 };
}

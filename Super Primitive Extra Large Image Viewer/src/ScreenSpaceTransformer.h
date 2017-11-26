#pragma once
#include "Vector3.h"
class ScreenSpaceTransformer
{
public:
	ScreenSpaceTransformer(Vector2& dims);
	Vector2 getPixelLocation(Vector3& transformedVec);
	std::pair<Vector2, Vector2> getPixelLocation(Vector3& v1, Vector3& v2);
private:
	Vector2 dims;
};
#pragma once
#include "Vector3.h"
#include <SDL\SDL.h>
class Triangle
{
public:
	Triangle();
	~Triangle();
	Triangle(Vector3& v1, Vector3 &v2, Vector3& v3);
	void draw();
private:
	size_t verticeIndexes[3];
};

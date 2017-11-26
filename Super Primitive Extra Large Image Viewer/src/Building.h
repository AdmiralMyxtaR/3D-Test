#pragma once
#include "Triangle.h"
#include <vector>
class Building
{
public:
	Building(Vector3& pos, Vector3 &dims);
	void draw(SDL_Renderer* renderer, int screnHeight, Vector3& cameraPos, Vector3& cameraAngle);
private:
	std::vector<Triangle> polys;
};
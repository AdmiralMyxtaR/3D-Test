#pragma once
#include <vector>
#include "Triangle.h"
class Model
{
public:
	Model(Vector3& pos, SDL_Surface* texture, std::vector<Triangle>& polygons);
private:
	Vector3 pos;
	SDL_Surface* texture;
	std::vector<Triangle> polygons;
};
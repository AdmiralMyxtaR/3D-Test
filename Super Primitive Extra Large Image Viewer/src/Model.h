#pragma once
#include <vector>
#include "Triangle.h"
class Model
{
public:
	Model() = default;
	Model(Vector3& pos, SDL_Surface* texture, std::vector<Triangle>& polygons);
	void setPos(Vector3& pos);
	Vector3 getPos();
	void addPos(Vector3& v);
	void draw();
private:
	Vector3 pos;
	SDL_Surface* texture;
	std::vector<Triangle> polygons;
};
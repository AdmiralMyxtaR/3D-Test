#pragma once
#include <vector>
#include "Triangle.h"
#include "Texture.h"
class Model
{
public:
	Model() = default;
	Model(Vector3& pos, Texture& texture, std::vector<Triangle>& polygons);
	
	Vector3 getPos();
	SDL_Surface* getTexture();

	void setPos(Vector3& pos);
	void addPos(Vector3& v);

	void draw();
private:
	Vector3 pos;
	Texture texture;
	std::vector<Triangle> polygons;
};
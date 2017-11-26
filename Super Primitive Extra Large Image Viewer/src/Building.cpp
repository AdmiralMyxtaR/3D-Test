#include "Building.h"

Building::Building(Vector3& pos, Vector3 &dims)
{
	Vector3 v1 = pos + Vector3(0.0, dims.y, 0.0);
	Vector3 v2 = pos + Vector3(dims.x, dims.y, 0);
	Vector3 v3 = pos;
	this->polys.push_back(Triangle(v1, v2, v3)); //1
	v1 = pos;
	v2 = pos + Vector3(dims.x, 0, 0);
	v3 = pos + Vector3(dims.x, dims.y, 0);
	this->polys.push_back(Triangle(v1, v2, v3)); //2
	v1 = pos + Vector3(dims.x, dims.y, 0);
	v2 = pos + Vector3(dims.x, dims.y, dims.z);
	v3 = pos + Vector3(dims.x, 0, 0);
	this->polys.push_back(Triangle(v1, v2, v3)); //3

	v1 = pos + Vector3(dims.x, 0, 0);
	v2 = pos + Vector3(dims.x, 0, dims.z);
	v3 = pos + Vector3(dims.x, dims.y, dims.z);
	this->polys.push_back(Triangle(v1, v2, v3)); //4
	v1 = pos + Vector3(0, dims.y, dims.z);
	v2 = pos + Vector3(0, dims.y, 0); //4
	v3 = pos + Vector3(dims.x, dims.y, 0);
	this->polys.push_back(Triangle(v1, v2, v3)); //5
	v1 = pos + Vector3(dims.x, dims.y, 0); 
	v2 = pos + Vector3(dims.x, dims.y, dims.z);
	v3 = pos + Vector3(0, dims.y, dims.z);
	this->polys.push_back(Triangle(v1, v2, v3)); //6

	v1 = pos + Vector3(0, dims.y, dims.z);
	v2 = pos + dims;
	v3 = pos + Vector3(0, 0, dims.z);
	this->polys.push_back(Triangle(v1, v2, v3)); //7
	v1 = pos +Vector3(0,0,dims.z);
	v2 = pos + Vector3(dims.x, 0, dims.z);
	v3 = pos + dims;
	this->polys.push_back(Triangle(v1, v2, v3)); //8
	v1 = pos;
	v2 = pos + Vector3(dims.x, 0, 0);
	v3 = pos + Vector3(dims.x, 0, dims.z);
	this->polys.push_back(Triangle(v1, v2, v3)); //9

	v1 = pos + Vector3(dims.x, 0, dims.z);
	v2 = pos;
	v3 = pos + Vector3(0, 0, dims.z);
	this->polys.push_back(Triangle(v1, v2, v3)); //10
	v1 = pos + Vector3(0, dims.y, dims.z);
	this->polys.push_back(Triangle(v1, v2, v3));
	v1 = pos + Vector3(0, dims.y, 0);
	v2 = pos + Vector3(0, dims.y, dims.z);
	v3 = pos;
	this->polys.push_back(Triangle(v1, v2, v3));
}
void Building::draw(SDL_Renderer * renderer, int screnHeight, Vector3 & cameraPos, Vector3 & cameraAngle)
{
	for (auto& it : polys)
	{
		it.draw();
	}
}
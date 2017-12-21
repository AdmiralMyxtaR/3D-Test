#pragma once
#include "Vector3.h"
#include <SDL\SDL.h>
class Model;
class Triangle
{
public:
	Triangle();
	~Triangle();
	Triangle(Vector3& v1, Vector3 &v2, Vector3& v3);
	Triangle(Vector3& v1, Vector3 &v2, Vector3& v3, Vector2& tv1, Vector2& tv2, Vector2& tv3);
	void setTextureVertices(Vector2& tv1, Vector2& tv2, Vector2& tv3);
	std::tuple<const Vector3&, const Vector3&, const Vector3&> getVertices() const;
	void draw();
	void drawAsPartOfModel(Model& model);
private:
	Vector3 vertices[3];
	Vector3 normal;
	Vector2 textureVerices[3];

	Vector3 createNormal();
	void drawFlatBottom(Model& model, Vector2& v1, Vector2& v2, Vector2& v3);
	void drawFlatTop(Model& model, Vector2& v1, Vector2& v2, Vector2& v3);
};

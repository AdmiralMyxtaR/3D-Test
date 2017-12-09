#include "Triangle.h"
#include "Matrix3.h"
#include "Draw.h"
#include "globals.h"
#include "ScreenSpaceTransformer.h"
#include "graphics.h"
#include "VerticeList.h"
Triangle::Triangle()
{
}

Triangle::~Triangle()
{
}

Triangle::Triangle(Vector3 & v1, Vector3 & v2, Vector3 & v3)
{
	this->vertices[0] = v1;
	this->vertices[1] = v2;
	this->vertices[2] = v3;
}

Triangle::Triangle(Vector3 & v1, Vector3 & v2, Vector3 & v3, Vector2 & tv1, Vector2 & tv2, Vector2 & tv3)
{
	this->vertices[0] = v1;
	this->vertices[1] = v2;
	this->vertices[2] = v3;
	this->textureVerices[0] = tv1;
	this->textureVerices[1] = tv2;
	this->textureVerices[2] = tv3;
}
void Triangle::setTextureVertices(Vector2 & tv1, Vector2 & tv2, Vector2 & tv3)
{
	this->textureVerices[0] = tv1;
	this->textureVerices[1] = tv2;
	this->textureVerices[2] = tv3;
}
std::tuple<const Vector3&, const Vector3&, const Vector3&> Triangle::getVertices()
{
	return { vertices[0], vertices[1], vertices[2] };
}
void Triangle::draw()
{
	Vector2 points[4];
	double zValues[3];
	for (int i = 0; i < 3; ++i)
	{
		Vector3 screenSpace = *globals::rotationMatrix*(this->vertices[i]-*globals::cameraPos);
		points[i] = globals::sst->getPixelLocation(screenSpace);	
	}
	points[3] = points[0];
	for (int i = 0; i < 3; ++i) globals::graphics->drawLine(points[i], points[i + 1], 255, 255, 255);
}
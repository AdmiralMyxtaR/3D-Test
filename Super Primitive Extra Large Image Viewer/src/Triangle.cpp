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
	this->normal = this->createNormal();
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
	double cameraDot = this->normal.dot(*globals::cameraPos);
	if (cameraDot >= 0.0)
	{
		Vector2 points[4];
		double zValues[3];
		for (int i = 0; i < 3; ++i)
		{
			Vector3 screenSpace = *globals::rotationMatrix*(this->vertices[i] - *globals::cameraPos);
			points[i] = globals::sst->getPixelLocation(screenSpace);
		}
		points[3] = points[0];
		for (int i = 0; i < 3; ++i) globals::graphics->drawLine(points[i], points[i + 1], 255, 255, 255);
	}
}

Vector3 Triangle::createNormal()
{
	double x1 = vertices[0].x;
	double x2 = vertices[1].x;
	double x3 = vertices[2].x;
	double y1 = vertices[0].y;
	double y2 = vertices[1].y;
	double y3 = vertices[2].y;
	double z1 = vertices[0].z;
	double z2 = vertices[1].z;
	double z3 = vertices[2].z;
	double retX = (y2 - y1)*(z3 - z1) - (z2 - z1)*(y3 - y1);
	double retY = (z2 - z1)*(x3 - x1) - (x2 - x1)*(z3 - z1);
	double retZ = (x2 - x1)*(y3 - y1) - (y2 - y1)*(x3 - x1);
	return Vector3(retX, retY, retZ);
}

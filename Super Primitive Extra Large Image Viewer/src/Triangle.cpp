#include "Triangle.h"
#include "Matrix3.h"
#include "Draw.h"+
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
	this->verticeIndexes[0] = globals::verticeList->lookup(v1);
	this->verticeIndexes[1] = globals::verticeList->lookup(v2);
	this->verticeIndexes[2] = globals::verticeList->lookup(v3);
}

void Triangle::draw()
{
	SDL_Point points[4];
	double zValues[3];
	for (int i = 0; i < 3; ++i)
	{
		Vector3 screenSpace = globals::verticeList->transformedVertices[verticeIndexes[i]];
		Vector2 transformed = globals::sst->getPixelLocation(screenSpace);
		points[i] = { int(transformed.x),int(transformed.y) };		
	}
	points[3] = points[0];
	for (int i = 0; i < 3; ++i) globals::graphics->drawLine(Vector2(points[i].x,points[i].y), Vector2(points[i + 1].x,points[i + 1].y), 255, 255, 255);
}
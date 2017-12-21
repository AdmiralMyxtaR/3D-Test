#include "Triangle.h"
#include "Matrix3.h"
#include "Draw.h"
#include "globals.h"
#include "ScreenSpaceTransformer.h"
#include "graphics.h"
#include "VerticeList.h"
#include "Model.h"
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
	this->normal = this->createNormal();
}
void Triangle::setTextureVertices(Vector2 & tv1, Vector2 & tv2, Vector2 & tv3)
{
	this->textureVerices[0] = tv1;
	this->textureVerices[1] = tv2;
	this->textureVerices[2] = tv3;
}
std::tuple<const Vector3&, const Vector3&, const Vector3&> Triangle::getVertices() const
{
	return { vertices[0], vertices[1], vertices[2] };
}
void Triangle::draw()
{
	//pure wireframe rendering
	double cameraDot = this->normal.dot(*globals::cameraPos);
	if (cameraDot >= 0.0)
	{
		Vector2 points[4];
		for (int i = 0; i < 3; ++i)
		{
			Vector3 screenSpace = *globals::rotationMatrix*(this->vertices[i] - *globals::cameraPos);
			points[i] = globals::sst->getPixelLocation(screenSpace);
		}
		points[3] = points[0];
		for (int i = 0; i < 3; ++i) globals::graphics->drawLine(points[i], points[i + 1], 255, 255, 255);
	}
}

void Triangle::drawAsPartOfModel(Model& model)
{
	Vector3 posOffset = model.getPos();
	Vector3 v[3] = { vertices[0] + posOffset, vertices[1] + posOffset, vertices[2] + posOffset };
	Vector3 normal = (v[1] - v[0]).cross(v[2] - v[0]);
	double cameraDot = normal.dot(*globals::cameraPos);
	if (cameraDot >= 0.0) //if not culled by backface culling
	{
		Vector2 points[4];
		for (int i = 0; i < 3; ++i)
		{
			Vector3 screenSpace = *globals::rotationMatrix*(v[i] - *globals::cameraPos);
			points[i] = globals::sst->getPixelLocation(screenSpace);
		}
		points[3] = points[0];
		Vector2* sv[3] = {&points[0],&points[1],&points[2],}; //sorted vertices (in ascending Y order)
		for (int i = 0; i < 2; ++i)	if (sv[i]->y > sv[i + 1]->y) std::swap(sv[i], sv[i + 1]);
		double spl_x = sv[0]->x + (sv[1]->y - sv[0]->y) / (sv[2]->y - sv[0]->y) * (sv[2]->x - sv[0]->x);
		Vector2 splittingVertice(spl_x, sv[1]->y);
		//add clockwise major right/left branching here
		if (points[1].x > splittingVertice.x) //major left?
		{
			this->drawFlatBottom(model, points[0], points[1], splittingVertice);
			this->drawFlatTop(model, points[1], points[2], splittingVertice);
		}
		else
		{
			this->drawFlatBottom(model, points[0], splittingVertice, points[1]);
			this->drawFlatTop(model, splittingVertice, points[2], points[1]);
		}
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

void Triangle::drawFlatBottom(Model & model, Vector2 & v1, Vector2 & v2, Vector2& v3)
{
	
}

void Triangle::drawFlatTop(Model & model, Vector2 & v1, Vector2 & v2, Vector2 & v3)
{
	double slope1 = (v3.x - v1.x) / (v3.y - v1.y);
	double slope2 = (v3.x - v2.x) / (v3.y - v2.y);
	for (int y = v1.y; y < v3.y; ++y)
	{
		double px1 = slope1*(y - v1.y) + v1.x;
		double px2 = slope2*(y - v2.y) + v2.x;
		if (abs(px1) > 2000 || abs(px2 > 2000)) return;
		for (int x = px1; x < px2; ++x)
		{
			globals::graphics->setPixel(x, y, 0, 255, 0);
		}
	}
}

#pragma once
#include <my\math.h>
class Body
{
public:
	Body();
	Body(double posX, double posY, double posZ, double mass);
	double contribute(double posX, double posY);
	~Body();

private:
	double posX, posY, posZ, mass;
};

Body::Body()
{
}

inline Body::Body(double posX, double posY, double posZ, double mass)
{
	this->posX = posX;
	this->posY = posY;
	this->posZ = posZ;
	this->mass = mass;
}

inline double Body::contribute(double posX, double posY)
{
	double magnitude = mass / (Math.sqr(posX - this->posX) + Math.sqr(posY - this->posY));
	return 0.0;
}

Body::~Body()
{
}
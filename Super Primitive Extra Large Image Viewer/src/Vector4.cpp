#include "Vector4.h"
#include <cmath>
Vector4::Vector4()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}

Vector4::Vector4(double x, double y, double z, double w)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

Vector4 Vector4::operator*(Vector4 & other)
{
	return Vector4(this->x*other.x, this->y*other.y, this->z*other.z, this->w*other.w);
}

Vector4 Vector4::operator+(Vector4 & other)
{
	return Vector4(this->x + other.x, this->y + other.y, this->z + other.z, this->w + other.w);
}

Vector4 Vector4::operator-(Vector4 & other)
{
	return Vector4(this->x - other.x, this->y - other.y, this->z - other.z, this->w - other.w);
}

Vector4 Vector4::operator/(Vector4 & other)
{
	return Vector4(this->x / other.x, this->y / other.y, this->z / other.z, this->w / other.w);
}

Vector4 Vector4::operator*(double mult)
{
	return Vector4(this->x*mult, this->y*mult, this->z*mult, this->w*mult);
}

Vector4 Vector4::operator/(double div)
{
	return Vector4(this->x / div, this->y / div, this->z / div, this->w / div);
}

void Vector4::operator*=(Vector4 & other)
{
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.y;
	this->w *= other.w;
}

void Vector4::operator*=(double m)
{
	this->x *= m;
	this->y *= m;
	this->z *= m;
	this->w *= m;
}

void Vector4::operator+=(Vector4 & other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	this->w += other.w;
}

void Vector4::operator/=(Vector4 & other)
{
	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;
	this->w /= other.w;
}

void Vector4::operator/=(double d)
{
	this->x /= d;
	this->y /= d;
	this->z /= d;
	this->w /= d;
}

void Vector4::operator-=(Vector4 & other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	this->w -= other.w;
}

bool Vector4::operator==(Vector4 & other)
{
	return x == other.x&&y == other.y&&z == other.z&&w == other.w;
}

Vector4 operator-(Vector4 & v)
{
	return Vector4(-v.x, -v.y, -v.z, -v.w);
}

Vector4::operator Vector2()
{
	return Vector2(x, y);
}

Vector4::operator Vector3()
{
	return Vector3(x, y, z);
}

double Vector4::length()
{
	return sqrt(x*x + y*y + z*z + w*w);
}

void Vector4::nullify()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
	this->w = 0;
}

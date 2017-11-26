#include "Vector3.h"
#include <cmath>
Vector3::Vector3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3::Vector3(double x, double y, double z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

Vector3 Vector3::operator*(Vector3 & other)
{
	return Vector3(this->x*other.x, this->y*other.y, this->z*other.z);
}

Vector3 Vector3::operator+(Vector3 & other)
{
	return Vector3(this->x + other.x, this->y + other.y, this->z + other.z);
}

Vector3 Vector3::operator-(Vector3 & other)
{
	return Vector3(this->x - other.x, this->y - other.y, this->z - other.z);
}

Vector3 Vector3::operator/(Vector3 & other)
{
	return Vector3(this->x / other.x, this->y / other.y, this->z / other.z);
}

Vector3 Vector3::operator*(double mult)
{
	return Vector3(this->x*mult, this->y*mult, this->z*mult);
}

Vector3 Vector3::operator/(double div)
{
	return Vector3(this->x / div, this->y / div, this->z / div);
}

void Vector3::operator*=(Vector3 & other)
{
	this->x *= other.x;
	this->y *= other.y;
	this->z *= other.z;
}

void Vector3::operator*=(double m)
{
	this->x *= m;
	this->y *= m;
	this->z *= m;
}

void Vector3::operator+=(Vector3 & other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
}

void Vector3::operator/=(Vector3 & other)
{
	this->x /= other.x;
	this->y /= other.y;
	this->z /= other.z;
}

void Vector3::operator/=(double d)
{
	this->x /= d;
	this->y /= d;
	this->z /= d;
}

void Vector3::operator-=(Vector3 & other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
}

bool Vector3::operator==(Vector3 & other)
{
	return this->x == other.x && this->y == other.y && this->z == other.z;
}

bool Vector3::operator!=(Vector3& rhs)
{
	return x != rhs.x || y != rhs.y || z != rhs.z;
}

double Vector3::dot(Vector3 & rhs)
{
	return x*rhs.x + y*rhs.y + z*rhs.z;
}

Vector3 Vector3::cross(Vector3 & rhs)
{
	return Vector3(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
}

Vector3::operator Vector2()
{
	return Vector2(x, y);
}

Vector3::operator Vec3_Tuple()
{
	return{ x,y,z };
}


double Vector3::length()
{
	return sqrt(x*x + y*y + z*z);
}

void Vector3::nullify()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vector3 operator-(Vector3 & v)
{
	return Vector3(-v.x, -v.y, -v.z);
}

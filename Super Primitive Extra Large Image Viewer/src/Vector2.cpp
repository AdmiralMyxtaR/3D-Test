#include "Vector2.h"
#include <SDL\SDL.h>
#include <cmath>
Vector2::Vector2()
{
	this->x = 0;
	this->y = 0;
}

Vector2::Vector2(double _x, double _y)
{
	this->x = _x;
	this->y = _y;
}
Vector2::Vector2(SDL_Rect& rect, bool initByPos)
{
	if (initByPos)
	{
		this->x = rect.x;
		this->y = rect.y;
	}
	else
	{
		this->x = rect.w;
		this->y = rect.y;
	}
}
Vector2 Vector2::zero()
{
	return Vector2(0, 0);
}

void Vector2::nullify()
{
	this->x = 0;
	this->y = 0;
}
bool Vector2::isNull()
{
	return (this->x == 0 && this->y == 0);
}
Vector2 Vector2::operator+(Vector2 &other)
{
	return Vector2(this->x + other.x, this->y + other.y);
}

Vector2 Vector2::operator-(Vector2 &other)
{
	return Vector2(this->x - other.x, this->y - other.y);
}

Vector2 Vector2::operator* (Vector2 &other)
{
	return Vector2(this->x * other.x, this->y * other.y);
}

Vector2 Vector2::operator/(Vector2 &other)
{
	return Vector2(this->x / other.x, this->y / other.y);
}

void Vector2::operator+=(Vector2 &other)
{
	this->x += other.x;
	this->y += other.y;
}

void Vector2::operator-=(Vector2 &other)
{
	this->x -= other.x;
	this->y -= other.y;
}

void Vector2::operator*=(Vector2 &other)
{
	this->x *= other.x;
	this->y *= other.y;
}

void Vector2::operator/=(Vector2 &other)
{
	this->x /= other.x;
	this->y /= other.y;
}

Vector2 Vector2::operator*(double mult)
{
	return Vector2(this->x*mult, this->y*mult);
}

Vector2 Vector2::operator/(double div)
{
	return Vector2(x / div, y / div);
}

void Vector2::operator*=(double mult)
{
	this->x *= mult;
	this->y *= mult;
}

bool Vector2::operator==(Vector2 & other)
{
	return (this->x == other.x && this->y == other.y);
}

/*double Vector2::dot(Vector2 v)
{
return this->x*v.x + this->y*v.y;
}
*/
double Vector2::length()
{
	return sqrt(x*x + y*y);
}

double Vector2::distance(Vector2 & other)
{
	Vector2 delta = *this - other;
	return delta.length();
}

double Vector2::dot(Vector2 & rhs)
{
	return x*rhs.x + y*rhs.y;
}

Vector2 Vector2::abs()
{
	return Vector2(std::abs(this->x), std::abs(this->y));
}

Vector2 operator-(Vector2 & v)
{
	return Vector2(-v.x, -v.y);
}

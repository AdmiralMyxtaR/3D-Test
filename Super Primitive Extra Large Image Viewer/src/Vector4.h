#pragma once
#include "Vector3.h"
struct Vector4
{
	double x, y, z, w;
	Vector4();
	Vector4(double x, double y, double z, double w);
	Vector4 operator*(Vector4& other);
	Vector4 operator+(Vector4& other);
	Vector4 operator-(Vector4& other);
	Vector4 operator/(Vector4& other);
	Vector4 operator*(double mult);
	Vector4 operator/(double div);
	friend Vector4 operator-(Vector4 &v);
	void operator*=(Vector4& other);
	void operator*=(double m);
	void operator+=(Vector4& other);
	void operator/=(Vector4& other);
	void operator/=(double d);
	void operator-=(Vector4& other);
	bool operator==(Vector4& other);
	operator Vector2();
	operator Vector3();
	double length();
	void nullify();
};
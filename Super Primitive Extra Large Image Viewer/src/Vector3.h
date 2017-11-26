#pragma once
#include "Vector2.h"
#include <tuple>
typedef std::tuple<double,double,double> Vec3_Tuple;
struct Vector3
{
	double x,y,z;
	Vector3();
	Vector3(double x, double y, double z);
	Vector3 operator*(Vector3& other);	
	Vector3 operator+(Vector3& other);
	Vector3 operator-(Vector3& other);
	Vector3 operator/(Vector3& other);
	Vector3 operator*(double mult);
	Vector3 operator/(double div);
	friend Vector3 operator-(Vector3 &v);
	void operator*=(Vector3& other);
	void operator*=(double m);
	void operator+=(Vector3& other);
	void operator/=(Vector3& other);	
	void operator/=(double d);
	void operator-=(Vector3& other);
	bool operator==(Vector3& other);
	bool operator!=(Vector3 & rhs);
	double dot(Vector3& rhs);
	Vector3 cross(Vector3& rhs);
	operator Vector2();
	operator Vec3_Tuple();
	double length();
	void nullify();
};
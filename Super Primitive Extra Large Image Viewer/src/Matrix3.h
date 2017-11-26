#pragma once
#include "Vector3.h"
class Matrix3
{
public:
	Matrix3();
	Matrix3(double e11, double e12, double e13, double e21, double e22, double e23, double e31, double e32, double e33);		
	Matrix3 operator*(Matrix3& other);
	Vector3 operator*(Vector3& v3);
	double elements[3][3];
};

Matrix3 rotateX(double theta);
Matrix3 rotateY(double theta);
Matrix3 rotateZ(double theta);
Matrix3 getRotationMatrix(Vector3& angle);
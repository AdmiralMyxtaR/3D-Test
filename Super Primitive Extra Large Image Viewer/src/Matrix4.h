#pragma once
#include "Vector4.h"
class Matrix4
{
public:
	Vector4 operator*(Vector4& v);

	double elements[4][4];
};

Matrix4 getPerspectiveMatrix();
#include "Matrix4.h"
#include "globals.h"
#include <cmath>
Vector4 Matrix4::operator*(Vector4 & v)
{
	return{
		v.x * this->elements[0][0] + v.y * this->elements[1][0] + v.z * this->elements[2][0] + v.w*this->elements[3][0],
		v.x * this->elements[0][1] + v.y * this->elements[1][1] + v.z * this->elements[2][1] + v.w*this->elements[3][1],
		v.x * this->elements[0][2] + v.y * this->elements[1][2] + v.z * this->elements[2][2] + v.w*this->elements[3][2],
		v.x * this->elements[0][3] + v.y * this->elements[1][3] + v.z * this->elements[2][3] + v.w*this->elements[3][3],
	};
}

Matrix4 getPerspectiveMatrix()
{
	double halfFov = *globals::fov / 2;
	double near = globals::cameraPos->z;
	double far = 1000;
	double aspectRatiob = 1920.0 / 1080;
	return{
		1.0 / (aspectRatiob*halfFov), 0, 0, 0,
		0, 1.0 / tan(halfFov),0,0,
		0,0,-(far + near) / (far - near),(-2 * far*near) / (far - near),
		0,0,-1,0,
	};
}

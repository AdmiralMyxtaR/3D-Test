#include "ZBuffer.h"
#include <string>
ZBuffer::ZBuffer(int width, int height)
{
	this->pixels = nullptr;
	this->rebuild(width, height);
}
bool ZBuffer::TestAndSet(int x, int y, double value)
{
	double rec = 1.0 / value;
	int offset = y*width + x;
	if (this->pixels[offset] > rec)
	{
		this->pixels[offset] = rec;
		return true;
	}
	return false;
}

void ZBuffer::clear()
{
	memset(this->pixels, 0, width * height * sizeof(double));
}

void ZBuffer::rebuild(int width, int height)
{
	if (pixels != nullptr) delete [] pixels;
	pixels = new double[width*height];
	this->width = width;
	this->height = height;
}

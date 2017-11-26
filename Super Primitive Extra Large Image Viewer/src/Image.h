#pragma once
#include <string>
class Image
{
public:
	Image(std::string path);
	~Image();

private:
	size_t width;
	size_t height;
	double scale;
	double posX;
	double posY;
};

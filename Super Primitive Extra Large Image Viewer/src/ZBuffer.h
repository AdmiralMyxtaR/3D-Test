#pragma once
class ZBuffer
{
public:
	ZBuffer() = default;
	ZBuffer(int width, int height);
	~ZBuffer();
	//returns true if the pixel should be drawn
	bool TestAndSet(int x, int y, double value);
	void clear();
	void rebuild(int width, int height);
private:
	double* pixels;
	int width;
	int height;
};
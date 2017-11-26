#pragma once
#include <map>
#include <vector>
#include "Vector3.h"

class VerticeList
{
public:
	std::vector<Vector3> vertices;
	size_t lookup(Vector3& vertice);
	std::vector<Vector3> transformedVertices;
	void transform();
	void beginNewFrame();
	void discardVerticeMap();
	void rebuildVerticeMap();
private:
	std::map<std::tuple<double,double,double>, size_t> verticeIndexes;
	size_t lastIndex = 0;

};
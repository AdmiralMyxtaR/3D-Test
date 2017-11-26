#include "VerticeList.h"
#include "Matrix3.h"
#include "globals.h"
size_t VerticeList::lookup(Vector3 & vertice)
{
	size_t indexToReturn;
	//std::tuple<double, double, double> tupledVertice;
	try
	{
		indexToReturn = verticeIndexes.at(vertice);
	}
	catch (const std::out_of_range&)
	{
		indexToReturn = lastIndex;
		this->vertices.push_back(vertice);
		this->verticeIndexes[vertice] = indexToReturn;
		++lastIndex;
	}
	return indexToReturn;	
}

void VerticeList::transform()
{
	Matrix3 rotation = getRotationMatrix(*globals::cameraAngle);
	for (auto& it : this->vertices)
	{
		this->transformedVertices.push_back(rotation*(it-*globals::cameraPos));
	}
}

void VerticeList::beginNewFrame()
{
	size_t toReserve = this->transformedVertices.size();
	this->transformedVertices.clear();
	this->transformedVertices.reserve(toReserve);
}

void VerticeList::discardVerticeMap()
{
	this->verticeIndexes.clear();
}

void VerticeList::rebuildVerticeMap()
{
	size_t index = 0;
	for (auto& it : vertices)
	{
		this->verticeIndexes[it] = index;
		++index;
	}
}

#include "Model.h"

Model::Model(Vector3 & pos, Texture& texture, std::vector<Triangle>& polygons)
{
	this->pos = pos;
	this->texture = texture;
	this->polygons = polygons;
}

void Model::setPos(Vector3 & pos)
{
	this->pos = pos;
}

Vector3 Model::getPos()
{
	return this->pos;
}

const Texture& Model::getTexture()
{
	return this->texture;
}

void Model::addPos(Vector3& v)
{
	this->pos += v;
}

void Model::draw()
{
	for (auto& it : this->polygons)
	{
		it.drawAsPartOfModel(*this);
	}
}

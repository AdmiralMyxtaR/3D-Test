#include "Model.h"

Model::Model(Vector3 & pos, SDL_Surface * texture, std::vector<Triangle>& polygons)
{
	this->pos = pos;
	this->texture = texture;
	this->polygons = polygons;
}

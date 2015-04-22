#include "Entity.h"


Entity::Entity()
{
	transform = NULL;
	graphics = NULL;
	physics = NULL;
}


Entity::~Entity()
{
	delete transform;
	delete graphics;
	delete physics;
}

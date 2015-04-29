#include "World.h"


World::World()
{
}


World::~World()
{
}

void World::addEntity(Entity *_entity)
{
	entities.push_back(_entity);
}

void World::UpdateTime()
{
	currentTime = deltaClock.getElapsedTime();
	dt = currentTime.asSeconds();
}

void World::RestartTime()
{
	deltaClock.restart();
}

float World::getDt()
{
	return dt;
}
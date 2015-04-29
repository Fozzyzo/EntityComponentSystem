#include "SystemManager.h"


SystemManager::SystemManager()
{
}


SystemManager::~SystemManager()
{
}


void SystemManager::Update(World *_world, sf::RenderWindow &_window)
{
	for (int i = 0; i < _world->getEntities().size(); i++)
	{
		renderer.Update(_world->getEntity(i), _window);
		physics.Update(_world->getEntity(i), _world);
	}
}

#include "SystemManager.h"


SystemManager::SystemManager()
{
}


SystemManager::~SystemManager()
{
}


void SystemManager::Update(Entity *_entity, sf::RenderWindow &_window, float _dt)
{
	renderer.Update(_entity, _window);
	physics.Update(_entity, _dt);
}

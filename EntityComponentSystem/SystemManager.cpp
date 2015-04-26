#include "SystemManager.h"


SystemManager::SystemManager()
{
}


SystemManager::~SystemManager()
{
}


void SystemManager::Update(Entity &_entity, sf::RenderWindow &_window)
{
	renderer.Update(_entity, _window);
}

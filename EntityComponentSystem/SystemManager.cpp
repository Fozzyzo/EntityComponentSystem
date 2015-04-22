#include "SystemManager.h"


SystemManager::SystemManager()
{
}


SystemManager::~SystemManager()
{
}

void SystemManager::AddSystem(System _system)
{
	systems.push_back(_system);
}

void SystemManager::Update(Entity _entity)
{
	for (int i = 0; i < systems.size(); i++)
	{
		systems[i].Update(_entity.graphics);
	}
}

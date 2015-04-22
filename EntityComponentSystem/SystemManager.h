#pragma once
#include <vector>
#include "System.h"
class SystemManager
{
public:
	SystemManager();
	~SystemManager();
	void AddSystem(System _system);
	void Update(Entity _entity);

private:
	std::vector<System> systems;

};


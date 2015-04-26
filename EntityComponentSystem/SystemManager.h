#pragma once
#include <vector>
#include "RenderingSystem.h"
#include "PhysicsSystem.h"

class SystemManager
{
public:
	SystemManager();
	~SystemManager();
	void Update(Entity &_entity, sf::RenderWindow &_window);

	RenderingSystem renderer;
	PhysicsSystem physics;
};


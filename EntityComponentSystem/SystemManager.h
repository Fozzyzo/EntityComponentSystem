#pragma once
#include <vector>
#include "RenderingSystem.h"
#include "PhysicsSystem.h"
#include "World.h"

class SystemManager
{
public:
	SystemManager();
	~SystemManager();
	void Update(World *_world, sf::RenderWindow &_window);

	RenderingSystem renderer;
	PhysicsSystem physics;
};


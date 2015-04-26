#pragma once
#include "Entity.h"
#include <cassert>
class System
{
public:
	System();
	~System();
	virtual void Update(Entity &_entity, sf::RenderWindow &_window);
};

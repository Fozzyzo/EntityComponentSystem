#pragma once
#include "SFML\Graphics.hpp"
#include "Component.h"
class PhysicsComponent : 
	public Component
{
public:
	PhysicsComponent();
	~PhysicsComponent();
	sf::Vector2f velocity;
};


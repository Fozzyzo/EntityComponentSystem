#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Component.h"

class TransformComponent : 
	public Component
{
public:

	TransformComponent();
	~TransformComponent();

	sf::Vector2f position;
	float rotation;
	sf::Vector2f scale;
};


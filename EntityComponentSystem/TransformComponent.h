#pragma once
#include <SFML\System.hpp>
#include "Component.h"
#include "BoundingCircle.h"

class TransformComponent : 
	public Component
{
public:

	TransformComponent();
	~TransformComponent();
	BoundingCircle* bounding;
	sf::Vector2f position;
	sf::Vector2f scale;
	float rotation;
	float perimeter;
};


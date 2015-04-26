#pragma once
#include "SFML\Graphics.hpp"
#include "Component.h"
class RenderComponent :
	public Component
{
public:
	
	RenderComponent();
	~RenderComponent();

	sf::IntRect rectangle;
	sf::CircleShape shape;
	sf::Texture texture;
	sf::Color color;
};


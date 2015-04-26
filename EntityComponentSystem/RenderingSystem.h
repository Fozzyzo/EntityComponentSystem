#pragma once
#include "System.h"
#include "RenderComponent.h"
#include "TransformComponent.h"

class RenderingSystem :
	public System
{
public:
	RenderingSystem();
	~RenderingSystem();
	void setTexture(Entity &_entity, sf::Image _image);	
	void setPosition(Entity &_entity, sf::Vector2f _position);
	void setRectangle(Entity &_entity, sf::IntRect _rect);
	void setShape(Entity &_entity, sf::CircleShape _shape);
	void setColor(Entity &_entity, sf::Color _color);

	void Update(Entity &_entity, sf::RenderWindow &_window);
};


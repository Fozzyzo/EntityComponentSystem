#pragma once
#include <string>
#include "Entity.h"
#include "PhysicsComponent.h"
#include "RenderComponent.h"
#include "TransformComponent.h"

class PhysicBall :
	public Entity
{
public:
	PhysicBall();
	~PhysicBall();
	void Update(sf::RenderWindow& _window);
	void setShape(sf::CircleShape _shape);
	void setTexture(std::string _filepath);
	void setRotation(float _rotation);
	void setPosition(sf::Vector2f _position);
	void setScale(sf::Vector2f _scale);

private:

	sf::CircleShape shape;
};


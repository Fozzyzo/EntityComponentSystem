#include "RenderingSystem.h"


RenderingSystem::RenderingSystem()
{
}


RenderingSystem::~RenderingSystem()
{
}

void RenderingSystem::setPosition(Entity &_entity, sf::Vector2f _position)
{
	_entity.transform->position = _position;
}

void RenderingSystem::Update(Entity &_entity , sf::RenderWindow &_window)
{	
	if (_entity.transform->position != _entity.graphics->shape.getPosition())
	{
		_entity.graphics->shape.setPosition(_entity.transform->position);
	}

	_window.draw(_entity.graphics->shape);
}

void RenderingSystem::setTexture(Entity &_entity, sf::Image _image)
{
	_entity.graphics->texture.loadFromImage(_image);
	_entity.graphics->shape.setTexture(&_entity.graphics->texture);
}

void RenderingSystem::setRectangle(Entity &_entity, sf::IntRect rect)
{
	_entity.graphics->rectangle = rect;
}

void RenderingSystem::setShape(Entity &_entity, sf::CircleShape _shape)
{
	_entity.graphics->shape = _shape;
}

void RenderingSystem::setColor(Entity &_entity, sf::Color _color)
{
	_entity.graphics->shape.setFillColor(_color);
}

#include "RenderingSystem.h"


RenderingSystem::RenderingSystem()
{
}


RenderingSystem::~RenderingSystem()
{
}

void RenderingSystem::setPosition(Entity *_entity, sf::Vector2f _position)
{
	_entity->transform->position = _position;
}

void RenderingSystem::Update(Entity *_entity , sf::RenderWindow &_window)
{	
	if (_entity->transform->position != _entity->graphics->shape.getPosition())
	{
		_entity->graphics->shape.setPosition(_entity->transform->position);
		_entity->transform->bounding->centerPos.x = _entity->transform->position.x + _entity->graphics->shape.getRadius();
		_entity->transform->bounding->centerPos.y = _entity->transform->position.y + _entity->graphics->shape.getRadius();
	}
	
	_window.draw(_entity->graphics->shape);
}

void RenderingSystem::setTexture(Entity *_entity, sf::Image _image)
{
	_entity->graphics->texture.loadFromImage(_image);
	_entity->graphics->shape.setTexture(&_entity->graphics->texture);
	_entity->transform->bounding->radius = _entity->graphics->shape.getRadius();
}

void RenderingSystem::setRectangle(Entity *_entity, sf::IntRect rect)
{
	_entity->graphics->shape.setTextureRect(rect);
}

void RenderingSystem::setShape(Entity *_entity, sf::CircleShape _shape)
{
 	_entity->graphics->shape = _shape;
	_entity->graphics->boundingBox = sf::FloatRect(_entity->transform->position.x, _entity->transform->position.y,
									_entity->graphics->shape.getRadius() * 2, _entity->graphics->shape.getRadius() * 2);
	_entity->transform->perimeter = 2 * 3,1415926535 * _entity->graphics->shape.getRadius();
}

void RenderingSystem::setColor(Entity *_entity, sf::Color _color)
{
	_entity->graphics->shape.setFillColor(_color);
}

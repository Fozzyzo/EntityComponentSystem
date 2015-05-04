#include "PhysicsSystem.h"
#include <iostream>


PhysicsSystem::PhysicsSystem()
{
}


PhysicsSystem::~PhysicsSystem()
{
}

void PhysicsSystem::setMass(Entity *_entity, float _mass)
{
	_entity->physics->mass = _mass;
}

void PhysicsSystem::setElasticity(Entity *_entity, float _elasticityMultiplier)
{
	_entity->physics->elasticityMultiplier = _elasticityMultiplier;
}

void PhysicsSystem::Update(Entity *_entity, World* _world)
{
	GroundCollisionDetection(_entity, _world->getDt());
	WallCollisionDetection(_entity);
	SimulatePhysics(_entity, _world->getDt());
}

void PhysicsSystem::SimulatePhysics(Entity *_entity, float _dt)
{
	_entity->physics->velocity.y += _dt * g;
	_entity->transform->position.y += _entity->physics->velocity.y;
}

void PhysicsSystem::GroundCollisionDetection(Entity *_entity, float dt)
{
	if (_entity->transform->position.y >= 600 - _entity->graphics->shape.getRadius() * 2
		&& _entity->physics->velocity.y >= 0)
	{
		_entity->transform->position.y = 600 - _entity->graphics->shape.getRadius() * 2;
		_entity->physics->velocity.y = -_entity->physics->velocity.y * 
										_entity->physics->elasticityMultiplier;
	}
}

void PhysicsSystem::WallCollisionDetection(Entity *_entity)
{
	if (_entity->transform->position.x > 800 - _entity->graphics->shape.getRadius() * 2
		|| _entity->transform->position.x < 0)
	{
		_entity->physics->velocity.x = -_entity->physics->velocity.x;
		
	}
}


void PhysicsSystem::EntityCollisionDetection(Entity* _entity, World *_world)
{
	for (int i = 0; i < _world->entities.size(); ++i)
	{
		if(_entity->transform->position > _world->entities[i]->transform->position)
	}
}



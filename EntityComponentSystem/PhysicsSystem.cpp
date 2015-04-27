#include "PhysicsSystem.h"


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

void PhysicsSystem::Update(Entity *_entity, float _dt)
{
	GroundCollisionDetection(_entity);
	SimulatePhysics(_entity, _dt);	
}

void PhysicsSystem::SimulatePhysics(Entity *_entity, float _dt)
{
	_entity->physics->velocity.y += _dt * g;
	_entity->transform->position.y += _entity->physics->velocity.y;
}

void PhysicsSystem::GroundCollisionDetection(Entity *_entity)
{
	if (_entity->transform->position.y > 600 - _entity->graphics->shape.getRadius() * 2
		&& _entity->physics->velocity.y > 0)
	{
		_entity->physics->velocity.y = -_entity->physics->velocity.y * 
										_entity->physics->elasticityMultiplier;
	}
}



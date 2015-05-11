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
	//EntityCollisionDetection(_entity, _world);
}

void PhysicsSystem::SimulatePhysics(Entity *_entity, float _dt)
{	
	_entity->transform->position.y += _entity->physics->velocity.y + (_dt * g / 2);
	_entity->physics->velocity.y += g * _dt;
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
		if (_entity->transform->bounding->Intersects(_world->entities[i]->transform->bounding));
		{		
			std::cout << "intersection" << std::endl;
			CountNewVelocities(_entity, _world->entities[i]);
		}
	}
}

void PhysicsSystem::CountNewVelocities(Entity* _entity1, Entity* _entity2)
{
	sf::Vector2f normal = _entity1->transform->bounding->centerPos - _entity2->transform->bounding->centerPos;

	sf::Vector2f newVelocity1;
	sf::Vector2f newVelocity2;

	newVelocity1.x = (normal.x * _entity1->physics->velocity.x) - (normal.x * _entity2->physics->velocity.x);
	newVelocity1.y = (normal.y * _entity1->physics->velocity.y) - (normal.x * _entity2->physics->velocity.y);

	newVelocity2.x = (normal.x * _entity2->physics->velocity.x) - (normal.x * _entity1->physics->velocity.x);
	newVelocity2.y = (normal.y * _entity2->physics->velocity.y) - (normal.y * _entity2->physics->velocity.y);

	_entity1->physics->velocity = newVelocity1;
	_entity2->physics->velocity = newVelocity2;
}



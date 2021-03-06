#pragma once
#include "System.h"
#include "PhysicsComponent.h"
#include "World.h"

//acceleration of gravity
#define g 10
#define PI 3.14159265359
class PhysicsSystem :
	public System
{
public:
	PhysicsSystem();
	~PhysicsSystem();
	void setMass(Entity *_entity, float _mass);
	/*Sets the elasticity multiplier for an object on impact, normally ranging from 0 to 1
	for 1 being fully elastic*/	
	void setElasticity(Entity *_entity, float _elasticityMultiplier);
	void Update(Entity *_entity, World* _world);

private:
	
	void CountNewVelocities(Entity *_entity1, Entity *_entity2);
	void SimulatePhysics(Entity *_entity, float _dt);
	void GroundCollisionDetection(Entity *_entity, float dt);
	void WallCollisionDetection(Entity *_entity);
	void EntityCollisionDetection(Entity *_entity, World *_world);
};


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
};


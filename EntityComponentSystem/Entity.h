#pragma once
#include <unordered_map>
#include "RenderComponent.h"
#include "TransformComponent.h"
#include "PhysicsComponent.h"
class Entity
{
public:
	Entity();
	~Entity();
	
	TransformComponent* transform;
	RenderComponent* graphics;
	PhysicsComponent* physics;
};


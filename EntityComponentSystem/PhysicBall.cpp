#include "PhysicBall.h"


PhysicBall::PhysicBall()
{
	transform = new TransformComponent;
	graphics = new RenderComponent;
	physics = new PhysicsComponent;
}


PhysicBall::~PhysicBall()
{
	delete transform;
	delete graphics;
	delete physics;
}

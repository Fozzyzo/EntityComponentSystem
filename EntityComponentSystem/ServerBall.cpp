#include "ServerBall.h"


ServerBall::ServerBall()
{
	transform = new TransformComponent;
	graphics = new RenderComponent;
}


ServerBall::~ServerBall()
{
	delete transform;
	delete graphics;
}

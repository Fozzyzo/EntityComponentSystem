#include "RenderingSystem.h"


RenderingSystem::RenderingSystem()
{
}


RenderingSystem::~RenderingSystem()
{
}

void RenderingSystem::Update(RenderComponent &_graphics)
{	
	_graphics.window.draw(_graphics.shape);
}

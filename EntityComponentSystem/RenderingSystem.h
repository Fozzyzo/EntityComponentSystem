#pragma once
#include "System.h"
#include "RenderComponent.h"
class RenderingSystem :
	public System
{
public:
	RenderingSystem();
	~RenderingSystem();
	void setTexture(RenderComponent &_graphics);
	void setRectangle(RenderComponent &_graphics);
	void Update(RenderComponent &_graphics);
};


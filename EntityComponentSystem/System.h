#pragma once
#include "Entity.h"
class System
{
public:
	System();
	~System();
	virtual void Update(Component &_component);
};


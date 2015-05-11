#include "BoundingCircle.h"

BoundingCircle::BoundingCircle()
{
}


BoundingCircle::~BoundingCircle()
{
}

bool BoundingCircle::Intersects(BoundingCircle *_circle)
{
	int dx = this->centerPos.x - _circle->centerPos.x;
	int dy = this->centerPos.y - _circle->centerPos.y;

	int distance = sqrt(dx * dx + dy * dy);

	if (distance >= this->radius + _circle->radius)
		return true;

	else
		return false;
}
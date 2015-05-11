#pragma once
#include <math.h>
#include <SFML\Graphics.hpp>

class BoundingCircle
{
public:

	BoundingCircle();
	~BoundingCircle();
	void setCenterPos();
	bool Intersects(BoundingCircle *_circle);
	sf::Vector2f centerPos;
	float radius;
};


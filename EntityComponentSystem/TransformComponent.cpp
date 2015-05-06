#include "TransformComponent.h"


TransformComponent::TransformComponent()
{
	bounding = new BoundingCircle;
}


TransformComponent::~TransformComponent()
{
	delete bounding;
}

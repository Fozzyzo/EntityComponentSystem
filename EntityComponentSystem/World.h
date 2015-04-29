#pragma once
#include <vector>
#include "Entity.h"

class World
{
public:
	World();
	~World();
	void addEntity(Entity* entity);
	Entity* getLastEntity(){ return entities.back(); }
	Entity* getEntity(int _i){ return entities[_i]; }
	std::vector<Entity*> getEntities(){ return entities; }
	void UpdateTime();
	void RestartTime();
	float getDt();
	std::vector<Entity*> entities;
	
private:

	float dt;
	sf::Time currentTime;
	sf::Clock deltaClock;
};


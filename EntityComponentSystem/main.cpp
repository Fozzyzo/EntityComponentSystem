#include <random>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "PhysicBall.h"
#include "SystemManager.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 600), "ECS / Physics simulation", sf::Style::Default, settings);
	sf::Image image;
	image.loadFromFile("smile.png");
	World* world = new World;
	sf::Vector2f randPos;
	bool isKeyPressed;
	sf::CircleShape tempShape = sf::CircleShape(30, 20);
	std::vector<Entity*> entities;
	
	SystemManager systemManager;
	isKeyPressed = false;

	//window.setFramerateLimit(60);

	while (window.isOpen())
	{

		sf::Event event;
		while (window.pollEvent(event))
		{

			switch (event.type)
			{

			case sf::Event::Closed:

				window.close();
				break;
			
			case sf::Event::KeyPressed:

				
   				if (event.key.code == sf::Keyboard::Space)
				{
               		isKeyPressed = true;

					world->addEntity(new PhysicBall);

					randPos = sf::Vector2f(sf::Vector2f(rand() % 760 - 40, rand() % 560 - 40));


 					systemManager.renderer.setPosition(world->getLastEntity(), randPos);
					systemManager.renderer.setTexture(world->getLastEntity(), image);
					systemManager.renderer.setShape(world->getLastEntity(), tempShape);
					systemManager.renderer.setColor(world->getLastEntity(), sf::Color::Blue);
					systemManager.physics.setElasticity(world->getLastEntity(), 0.7f);
					std::cout << "Ball added!" << std::endl;								
				}

				break;

			case sf::Event::KeyReleased:

				if (event.key.code == sf::Keyboard::Space)
				{
					isKeyPressed = false;
				}

				break;			
			}
		}

		
		window.clear();

		world->UpdateTime();

		if (world->getDt() > 0.001)
		std::cout << "DeltaTime: " << world->getDt() << std::endl;

		systemManager.Update(world, window);
	
 		window.display();
		world->RestartTime();
	}

	for (int i = 0; i < entities.size(); i++)
	{
		delete entities[i];
	}

	delete world;

	return 0;
}
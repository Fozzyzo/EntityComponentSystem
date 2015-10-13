#include <random>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "PhysicBall.h"
#include "ServerBall.h"
#include "SystemManager.h"

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 600), "ECS / Physics simulation", sf::Style::Default, settings);
	sf::Image image;
	image.loadFromFile("smile.png");
	World* world = new World;
	sf::Vector2f pos1;
	sf::Vector2f pos2;

	bool isKeyPressed;
	sf::CircleShape tempShape = sf::CircleShape(30, 20);
	sf::FloatRect boundingBox;
	sf::RectangleShape line(sf::Vector2f(1000, 10));
	line.setPosition(400, 300);
	line.setOrigin(500, 5);
	line.rotate(90);

	std::vector<Entity*> entities;

	sf::Vector2f point;
	
	SystemManager systemManager;
	isKeyPressed = false;

	PhysicBall* ball = new PhysicBall;
	ServerBall* serverBall = new ServerBall;
	world->addEntity(ball);

	pos1 = sf::Vector2f(sf::Vector2f(185, 300));
	pos2 = sf::Vector2f(sf::Vector2f(585, 300));

	systemManager.renderer.setPosition(world->getLastEntity(), pos1);
	systemManager.renderer.setTexture(world->getLastEntity(), image);
	systemManager.renderer.setShape(world->getLastEntity(), tempShape);
	systemManager.renderer.setColor(world->getLastEntity(), sf::Color::Blue);
	systemManager.physics.setElasticity(world->getLastEntity(), 0.7f);

	world->addEntity(serverBall);
	systemManager.renderer.setPosition(world->getLastEntity(), pos2);
	systemManager.renderer.setTexture(world->getLastEntity(), image);
	systemManager.renderer.setShape(world->getLastEntity(), tempShape);
	systemManager.renderer.setColor(world->getLastEntity(), sf::Color::Blue);

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
			

			case sf::Event::KeyReleased:

				if (event.key.code == sf::Keyboard::Space)
				{
					isKeyPressed = false;
				}

				break;			
			}
		}

	
		boundingBox = line.getGlobalBounds();

		window.clear();

		world->UpdateTime();

		if (world->getDt() > 0.001)
		std::cout << "DeltaTime: " << world->getDt() << std::endl;

		systemManager.Update(world, window);
		window.draw(line);
	
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
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

	bool isKeyPressed;
	PhysicBall ball;

	sf::Vector2f testVec;

	std::vector<Entity*> entities;
	
	SystemManager systemManager;
	isKeyPressed = false;
	systemManager.renderer.setPosition(ball, sf::Vector2f(rand() % 40 - 760, rand() % 40 - 560));
	systemManager.renderer.setTexture(ball, image);
	systemManager.renderer.setShape(ball, sf::CircleShape(32, 20));
	systemManager.renderer.setColor(ball, sf::Color::Blue);

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

					entities.push_back(new PhysicBall);

					systemManager.renderer.setPosition(*entities.back(), sf::Vector2f(rand() % 40 - 760, rand() % 40 - 560));
					systemManager.renderer.setTexture(*entities.back(), image);
					systemManager.renderer.setShape(*entities.back(), sf::CircleShape(32, 20));
					systemManager.renderer.setColor(*entities.back(), sf::Color::Blue);
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

		for (int i = 0; i < entities.size(); i++)
		{
			systemManager.Update(*entities[i], window);
		}
		
		window.display();
	}

	for (int i = 0; i < entities.size(); i++)
	{
		delete entities[i];
	}

	return 0;
}
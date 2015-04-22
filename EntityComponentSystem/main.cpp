#include <SFML/Graphics.hpp>
#include "PhysicBall.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "ECS / Physics simulation");
	PhysicBall ball;

	ball.setShape(sf::CircleShape(32, 30));
	ball.setTexture("smile.png");
	ball.setPosition(sf::Vector2f(200, 200));

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		ball.Update(window);
		window.display();
	}

	return 0;
}
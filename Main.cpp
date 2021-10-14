#include <SFML/Graphics.hpp>
#include "Utility.h"
#include "Creature.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "NEAT Environment");

	sf::Event event;

	std::vector<Creature> creatures;
	for (int i = 0; i < 20; i++)
	{
		Creature creature(20, 3);
		creature.body.move(Utility::RandomInt(0,800), Utility::RandomInt(0, 600));
		creatures.push_back(creature);
	}


	while (window.isOpen()) 
	{
		while (window.pollEvent(event)) 
		{
			switch (event.type)
			{
			case sf::Event::Closed:
			{
				window.close();
				break;
			}
			case sf::Event::KeyPressed:
			{
				switch (event.key.code)
				{
				case sf::Keyboard::R:
				{
					for (Creature& creature : creatures)
					{
						creature.RandomColour();
					}
					break;
				}
				}
			}
			default:
				break;
			}
		}

		window.clear();

		for (Creature& creature : creatures)
		{
			window.draw(creature.body);
		}

		window.display();
	}

	return 0;
}
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
		creature.body.setPosition(Utility::RandomInt(0, 800), Utility::RandomInt(0, 600));
		creature.eye.setPosition(creature.body.getPosition());
		creature.eye.setOrigin(4,12);
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
				case sf::Keyboard::E:
				{
					for (Creature& creature : creatures)
					{
						creature.Rotate(1);
					}
					break;
				}
				case sf::Keyboard::Q:
				{
					for (Creature& creature : creatures)
					{
						creature.Rotate(-1);
					}
					break;
				}
				case sf::Keyboard::W:
				{
					for (Creature& creature : creatures)
					{
						creature.Move(1, 0, 0, 0);
					}
					break;
				}
				case sf::Keyboard::S:
				{
					for (Creature& creature : creatures)
					{
						creature.Move(0, 1, 0, 0);
					}
					break;
				}
				case sf::Keyboard::A:
				{
					for (Creature& creature : creatures)
					{
						creature.Move(0, 0, 1, 0);
					}
					break;
				}
				case sf::Keyboard::D:
				{
					for (Creature& creature : creatures)
					{
						creature.Move(0, 0, 0, 1);
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
			window.draw(creature.eye);
		}

		window.display();
	}

	return 0;
}
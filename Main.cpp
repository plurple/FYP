#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "NEAT Environment");

	sf::Event event;

	while (window.isOpen()) 
	{
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed) 
			{
				window.close();
			}
		}

		window.clear();

		sf::CircleShape creature(20, 3);
		creature.setFillColor(sf::Color(100, 250, 50));
		window.draw(creature);

		window.display();
	}



	return 0;
}
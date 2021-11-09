#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "Vector2D.h"
#include "Button.h"
#include "NewEnvironment.h"


MainMenu MainMenu::menu;

MainMenu::~MainMenu()
{

}

void MainMenu::Cleanup()
{
	buttons.clear();
}

void MainMenu::Initialise(sf::RenderWindow* window)
{
	std::shared_ptr <Button> newButton = std::make_shared<Button>(vector2D(250, 250),
		sf::RectangleShape(sf::Vector2f(350, 50)), sf::Text("New Environment", font, 40));

	buttons.push_back(newButton);
}

void MainMenu::HandleInput(StackFSM* screen, sf::RenderWindow* window, sf::Event* event)
{
	for (auto butt : buttons)
	{
		sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
		if (butt->Hover(vector2D(mousePos.x, mousePos.y)))
		{
			butt->ChangeColour(sf::Color::Red);
			if (event->type == sf::Event::MouseButtonPressed)
			{
				if (event->mouseButton.button == sf::Mouse::Left)
				{
					screen->ChangeState(NewEnvironment::Instance());
				}
			}
		}
		else
			butt->ChangeColour(sf::Color::Cyan);
	}
}

void MainMenu::Update(StackFSM* screen, sf::RenderWindow* window)
{

}

void MainMenu::Render(StackFSM* screen, sf::RenderWindow* window)
{
	window->clear();

	for (auto butt : buttons)
	{
		vector2D pos = butt->position;

		window->draw(butt->rect);
		window->draw(butt->text);
	}

	window->display();
}



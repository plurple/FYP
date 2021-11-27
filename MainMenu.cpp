#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "Vector2D.h"
#include "Button.h"
#include "NewEnvironment.h"
#include "XorTest.h"

enum class Buttons
{
	NEWENVIRONMENT,
	XORTEST,
	EXIT
};

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
	std::shared_ptr <Button> newEnvironmentButton = std::make_shared<Button>(vector2D(260, 250),
		sf::RectangleShape(sf::Vector2f(325, 50)), sf::Text("New Environment", font, 40),
		static_cast<int>(Buttons::NEWENVIRONMENT));
	buttons.push_back(newEnvironmentButton);

	std::shared_ptr <Button> newXorButton = std::make_shared<Button>(vector2D(335, 300),
		sf::RectangleShape(sf::Vector2f(150, 50)), sf::Text("Xor Test", font, 40),
		static_cast<int>(Buttons::XORTEST));
	buttons.push_back(newXorButton);

	std::shared_ptr <Button> exitButton = std::make_shared<Button>(vector2D(375, 350),
		sf::RectangleShape(sf::Vector2f(75, 50)), sf::Text("Exit", font, 40),
		static_cast<int>(Buttons::EXIT));
	buttons.push_back(exitButton);
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
					ButtonClicked(screen, window, event, butt->ID);
					return;
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


void MainMenu::ButtonClicked(StackFSM* screen, sf::RenderWindow* window, sf::Event* event, int buttonID)
{
	switch (static_cast<Buttons>(buttonID))
	{
	case Buttons::NEWENVIRONMENT:
		screen->ChangeState(NewEnvironment::Instance());
		break;
	case Buttons::XORTEST:
		screen->ChangeState(XorTest::Instance());
		break;
	case Buttons::EXIT:
		window->close();
		break;
	default:
		break;
	}
}
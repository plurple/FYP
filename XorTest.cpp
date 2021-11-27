#include <SFML/Graphics.hpp>
#include "XorTest.h"
#include "Vector2D.h"
#include "Button.h"

enum class Buttons
{
};

XorTest XorTest::xorTest;

XorTest::~XorTest()
{

}

void XorTest::Cleanup()
{
	buttons.clear();
}

void XorTest::Initialise(sf::RenderWindow* window)
{
}

void XorTest::HandleInput(StackFSM* screen, sf::RenderWindow* window, sf::Event* event)
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

void XorTest::Update(StackFSM* screen, sf::RenderWindow* window)
{

}

void XorTest::Render(StackFSM* screen, sf::RenderWindow* window)
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


void XorTest::ButtonClicked(StackFSM* screen, sf::RenderWindow* window, sf::Event* event, int buttonID)
{
	switch (static_cast<Buttons>(buttonID))
	{
	default:
		break;
	}
}
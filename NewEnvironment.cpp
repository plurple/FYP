#include "NewEnvironment.h"
#include <SFML/Graphics.hpp>
#include "Vector2D.h"
#include "Button.h"
#include "Creature.h"

NewEnvironment NewEnvironment::environment;

NewEnvironment::~NewEnvironment()
{

}

void NewEnvironment::Cleanup()
{
	buttons.clear();
}

void NewEnvironment::Initialise(sf::RenderWindow* window)
{
	for (int i = 0; i < 20; i++)
	{
		std::shared_ptr<Creature> creature = std::make_shared<Creature>(20,3);
		creature->body.setPosition(Utility::RandomInt(0, 800), Utility::RandomInt(0, 600));
		creature->eye.setPosition(creature->body.getPosition());
		creature->eye.setOrigin(4, 12);
		creatures.push_back(creature);
	}

}

void NewEnvironment::HandleInput(StackFSM* screen, sf::RenderWindow* window, sf::Event* event)
{
	for (auto butt : buttons)
	{
	}
	
	switch (event->type)
		{
		case sf::Event::KeyPressed:
		{
			switch (event->key.code)
			{
			case sf::Keyboard::R:
			{
				for (auto creature : creatures)
				{
					creature->RandomColour();
				}
				break;
			}
			case sf::Keyboard::E:
			{
				for (auto creature : creatures)
				{
					creature->Rotate(1);
				}
				break;
			}
			case sf::Keyboard::Q:
			{
				for (auto creature : creatures)
				{
					creature->Rotate(-1);
				}
				break;
			}
			case sf::Keyboard::W:
			{
				for (auto creature : creatures)
				{
					creature->Move(1, 0, 0, 0);
				}
				break;
			}
			case sf::Keyboard::S:
			{
				for (auto creature : creatures)
				{
					creature->Move(0, 1, 0, 0);
				}
				break;
			}
			case sf::Keyboard::A:
			{
				for (auto creature : creatures)
				{
					creature->Move(0, 0, 1, 0);
				}
				break;
			}
			case sf::Keyboard::D:
			{
				for (auto creature : creatures)
				{
					creature->Move(0, 0, 0, 1);
				}
				break;
			}
			}
		}
		default:
			break;
	}
}

void NewEnvironment::Update(StackFSM* screen, sf::RenderWindow* window)
{

}

void NewEnvironment::Render(StackFSM* screen, sf::RenderWindow* window)
{
	window->clear();

	for (auto butt : buttons)
	{
		vector2D pos = butt->position;
		sf::Text text(butt->name, font, 40);
		text.setPosition(pos.X, pos.Y);

		window->draw(butt->rect);
		window->draw(text);
	}

	for (auto creature : creatures)
	{
		window->draw(creature->body);
		window->draw(creature->eye);
	}

	window->display();
}
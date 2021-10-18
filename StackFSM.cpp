#include <SFML/Graphics.hpp>
#include "StackFSM.h"
#include "MainMenu.h"
#include "NewEnvironment.h"


StackFSM::~StackFSM()
{
	delete window;
	delete event;
}

void StackFSM::Initialise()
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "NEAT Environment");
	event = new sf::Event;
	ChangeState(MainMenu::Instance());
}

void StackFSM::Cleanup()
{
	while (!states.empty())
	{
		states.back()->Cleanup();
		states.pop_back();
	}

	window->close();
}

void StackFSM::ChangeState(ScreenState* state)
{
	if (!states.empty())
	{
		states.back()->Cleanup();
		states.pop_back();
	}

	states.push_back(state);
	states.back()->Initialise(window);
}

void StackFSM::PushState(ScreenState* state)
{
	states.push_back(state);
	states.back()->Initialise(window);
}

void StackFSM::PopState()
{
	if (!states.empty())
	{
		states.back()->Cleanup();
		states.pop_back();
	}
}

void StackFSM::HandleInput()
{
	states.back()->HandleInput(this, event);
}

void StackFSM::Update()
{
	states.back()->Update(this, window);
}

void StackFSM::Render()
{
	states.back()->Render(this, window);
}

void StackFSM::Run()
{
	Initialise();

	while (window->isOpen())
	{
		while (window->pollEvent(*event))
		{
			switch (event->type)
			{
			case sf::Event::Closed:
			{
				window->close();
				break;
			}
			}

			Utility::DWORD time = Utility::GetTime();
			if (time - lastFrameUpdateTime > 30)
			{
				HandleInput();

				Update();

				lastFrameUpdateTime = time;
			}

			Render();
		}
	}

	Cleanup();
}

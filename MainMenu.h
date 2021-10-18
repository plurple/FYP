#pragma once
#include "ScreenState.h"

class MainMenu : public ScreenState
{
public:
	~MainMenu();

	void Initialise(sf::RenderWindow* window);
	void Cleanup();

	void HandleInput(StackFSM* screen, sf::Event* event);
	void Update(StackFSM* screen, sf::RenderWindow* window);
	void Render(StackFSM* screen, sf::RenderWindow* window);

	static MainMenu* Instance() { return &menu; }

protected:
	MainMenu() {}

private:
	static MainMenu menu;
};


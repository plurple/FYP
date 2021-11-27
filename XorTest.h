#pragma once
#include "ScreenState.h"
class XorTest : public ScreenState
{
public:
	~XorTest();

	void Initialise(sf::RenderWindow* window);
	void Cleanup();

	void HandleInput(StackFSM* screen, sf::RenderWindow* window, sf::Event* event);
	void Update(StackFSM* screen, sf::RenderWindow* window);
	void Render(StackFSM* screen, sf::RenderWindow* window);
	void ButtonClicked(StackFSM* screen, sf::RenderWindow* window, sf::Event* event, int buttonID);

	static XorTest* Instance() { return &xorTest; }

protected:
	XorTest() {}

private:
	static XorTest xorTest;
};


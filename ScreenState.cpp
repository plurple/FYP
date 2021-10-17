#include "ScreenState.h"

ScreenState::ScreenState()
{
	if (!font.loadFromFile("arial.ttf"))
	{
		// error...
	}
}

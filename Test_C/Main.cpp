#include "Main.h"

int main(int argc, char* argv[])
{
	globals.running = Setup();

	SDL_Event event;

	// Primary loop
	while (globals.running)
	{
		//handle any input from the user
		HandleEvents(event);

		Render();
	}

	Shutdown();

	return 1;
}
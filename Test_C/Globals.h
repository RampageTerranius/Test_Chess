#pragma once

#include <SDL.h>

class Globals
{
public:
	static const int BOARD_WIDTH = 8;
	static const int BOARD_HEIGHT = 8;

	const int WINDOW_WIDTH = 1024;
	const int WINDOW_HEIGHT = 768;

	bool running = false;

	PlayerColor currentPlayer = PLAYER_NONE;

	SDL_Renderer* renderer = nullptr;
	SDL_Window* window = nullptr;
}globals;
#pragma once

void Render()
{
	// Draw the board first.
	int rectWidth = globals.WINDOW_WIDTH / globals.BOARD_WIDTH;
	int rectHeight = globals.WINDOW_HEIGHT / globals.BOARD_HEIGHT;
	
	SDL_SetRenderDrawColor(globals.renderer, 255, 255, 255, 255);
	SDL_RenderClear(globals.renderer);

	SDL_SetRenderDrawColor(globals.renderer, 0, 0, 0, 255);

	for (int row = 0; row < globals.BOARD_WIDTH; row++)
	{
		int column = row % 2;
		int x = column;

		for (; column < (globals.BOARD_HEIGHT / 2) + (row % 2) ; column++)
		{	
			SDL_Rect rect;
			rect.w = rectWidth;
			rect.h = rectHeight;
			rect.x = x* rectWidth;
			rect.y = row * rectHeight;	
			x += 2;

			SDL_RenderFillRect(globals.renderer, &rect);
		}
	}

	SDL_RenderPresent(globals.renderer);
}
#pragma once

#include <SDL.h>

#include "mouse.h"
#include "keyboard.h"
#include "globals.h"

void UpdateEvents(SDL_Event& event)
{
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				globals.running = false;
				break;

			case SDLK_a:
				keyboard.a = true;
				break;

			case SDLK_d:
				keyboard.d = true;
				break;

			case SDLK_e:
				keyboard.e = true;
				break;

			case SDLK_w:
				keyboard.w = true;
				break;

			case SDLK_s:
				keyboard.s = true;
				break;

			case SDLK_h:
				keyboard.h = true;
				break;

			case SDLK_x:
				keyboard.x = true;
				break;

			case SDLK_MINUS:
				keyboard.minus = true;
				break;

			case SDLK_PLUS:
				keyboard.plus = true;
				break;

			case SDLK_LEFTBRACKET:
				keyboard.leftBracket = true;
				break;

			case SDLK_RIGHTBRACKET:
				keyboard.rightBracket = true;
				break;

			case SDLK_LSHIFT:
				keyboard.lShift = true;
				break;

			case SDLK_RSHIFT:
				keyboard.rShift = true;
				break;

			case SDLK_SPACE:
				keyboard.space = true;
				break;
			}

			break;

		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_a:
				keyboard.a = false;
				break;

			case SDLK_d:
				keyboard.d = false;
				break;

			case SDLK_e:
				keyboard.e = false;
				break;

			case SDLK_w:
				keyboard.w = false;
				break;

			case SDLK_s:
				keyboard.s = false;
				break;

			case SDLK_h:
				keyboard.h = false;
				break;

			case SDLK_x:
				keyboard.x = false;
				break;

			case SDLK_MINUS:
				keyboard.minus = false;
				break;

			case SDLK_PLUS:
				keyboard.plus = false;
				break;

			case SDLK_LSHIFT:
				keyboard.lShift = false;
				break;

			case SDLK_RSHIFT:
				keyboard.rShift = false;
				break;

			case SDLK_SPACE:
				keyboard.space = false;
				break;
			}
			break;

			//on mouse movement
		case SDL_MOUSEMOTION:
			SDL_GetMouseState(&mouse.x, &mouse.y);
			if (mouse.x < 0)
				mouse.x = 0;
			if (mouse.x > globals.WINDOW_WIDTH - 1)
				mouse.x = globals.WINDOW_WIDTH - 1;
			if (mouse.y < 0)
				mouse.y = 0;
			if (mouse.y > globals.WINDOW_HEIGHT - 1)
				mouse.y = globals.WINDOW_HEIGHT - 1;
			break;

			//on mouse button down
		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				mouse.left = true;
				break;

			case SDL_BUTTON_MIDDLE:
				mouse.middle = true;
				break;

			case SDL_BUTTON_RIGHT:
				mouse.right = true;
				break;
			}
			break;

			//on mouse button up
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				mouse.left = false;
				break;

			case SDL_BUTTON_MIDDLE:
				mouse.middle = false;
				break;

			case SDL_BUTTON_RIGHT:
				mouse.right = false;
				break;
			}
			break;
		}
	}
}

void HandleEvents(SDL_Event& event)
{
	// Run all input events first.
	UpdateEvents(event);

	// Now check if user has left clicked
	if (mouse.left)
	{


		mouse.left = false;
	}
}
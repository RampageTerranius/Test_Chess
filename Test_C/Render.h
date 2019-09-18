#pragma once

#include "Globals.h"
#include "Piece.h"

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

	for(int i = 0; i < globals.BOARD_WIDTH; i++)
		for (int n = 0; n < globals.BOARD_HEIGHT; n++)
		{			
			SDL_Rect renderLoc;

			int squareWidth = globals.WINDOW_WIDTH / globals.BOARD_WIDTH;
			int squareHeight = globals.WINDOW_HEIGHT / globals.BOARD_HEIGHT;

			renderLoc.x = (squareWidth * (i + 1)) - (squareWidth / 2);
			renderLoc.y = (squareHeight * (n + 1)) - (squareHeight / 2);

			switch (board.pieces[i][n].type)
			{
			case TYPE_PAWN:
				renderLoc.w = textures.pawn.Rect().w;
				renderLoc.h = textures.pawn.Rect().h;
				renderLoc.x -= renderLoc.w / 2;
				renderLoc.y -= renderLoc.h / 2;

				SDL_RenderCopy(globals.renderer, textures.pawn.Get(), &textures.pawn.Rect(), &renderLoc);
				break;

			case TYPE_ROOK:
				renderLoc.w = textures.rook.Rect().w;
				renderLoc.h = textures.rook.Rect().h;
				renderLoc.x -= renderLoc.w / 2;
				renderLoc.y -= renderLoc.h / 2;

				SDL_RenderCopy(globals.renderer, textures.rook.Get(), &textures.rook.Rect(), &renderLoc);
				break;

			case TYPE_BISHOP:
				renderLoc.w = textures.bishop.Rect().w;
				renderLoc.h = textures.bishop.Rect().h;
				renderLoc.x -= renderLoc.w / 2;
				renderLoc.y -= renderLoc.h / 2;

				SDL_RenderCopy(globals.renderer, textures.bishop.Get(), &textures.bishop.Rect(), &renderLoc);
				break;

			case TYPE_KNIGHT:
				renderLoc.w = textures.knight.Rect().w;
				renderLoc.h = textures.knight.Rect().h;
				renderLoc.x -= renderLoc.w / 2;
				renderLoc.y -= renderLoc.h / 2;

				SDL_RenderCopy(globals.renderer, textures.knight.Get(), &textures.knight.Rect(), &renderLoc);
				break;			

			case TYPE_QUEEN:
				renderLoc.w = textures.queen.Rect().w;
				renderLoc.h = textures.queen.Rect().h;
				renderLoc.x -= renderLoc.w / 2;
				renderLoc.y -= renderLoc.h / 2;

				SDL_RenderCopy(globals.renderer, textures.queen.Get(), &textures.queen.Rect(), &renderLoc);
				break;

			case TYPE_KING:
				renderLoc.w = textures.king.Rect().w;
				renderLoc.h = textures.king.Rect().h;
				renderLoc.x -= renderLoc.w / 2;
				renderLoc.y -= renderLoc.h / 2;

				SDL_RenderCopy(globals.renderer, textures.king.Get(), &textures.king.Rect(), &renderLoc);
				break;
			}
		}

	SDL_RenderPresent(globals.renderer);
}
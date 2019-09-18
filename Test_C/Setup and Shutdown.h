#pragma once

#include <string>
#include <iostream>
#include <Windows.h>

#include "Globals.h"

bool Setup()
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << ("Unable to initialize SDL_VIDEO: %s", SDL_GetError());
		return false;
	}

	if (SDL_Init(SDL_INIT_AUDIO) != 0)
	{
		std::cout << ("Unable to initialize SDL_AUDIO: %s", SDL_GetError());
		return false;
	}

	if (SDL_Init(SDL_INIT_EVENTS) != 0)
	{
		std::cout << ("Unable to initialize SDL_EVENTS: %s", SDL_GetError());
		return false;
	}

	if (SDL_Init(SDL_INIT_TIMER) != 0)
	{
		std::cout << ("Unable to initialize SDL_TIMER: %s", SDL_GetError());
		return false;
	}

	if (TTF_Init() != 0)
	{
		std::cout << ("Unable to initialize TTF: %s", TTF_GetError());
		return false;
	}

	//create main window
	Uint32 windowFlags = SDL_WINDOW_OPENGL;
	globals.window =  SDL_CreateWindow("Test", 0, 0, globals.WINDOW_WIDTH, globals.WINDOW_HEIGHT, windowFlags);

	Uint32 renderFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	globals.renderer = SDL_CreateRenderer(globals.window, -1, renderFlags);

	char buf[MAX_PATH];
	GetModuleFileName(nullptr, buf, MAX_PATH);

	std::string::size_type pos = std::string(buf).find_last_of("\\/");
	std::string programLocation = std::string(buf).substr(0, pos);


	// Load images
	if (!textures.pawn.Load(programLocation + "\\..\\Images\\p.jpg"))
		return false;
	if (!textures.rook.Load(programLocation + "\\..\\Images\\r.jpg"))
		return false;
	if (!textures.knight.Load(programLocation + "\\..\\Images\\kn.jpg"))
		return false;	
	if (!textures.bishop.Load(programLocation + "\\..\\Images\\b.jpg"))
		return false;
	if (!textures.queen.Load(programLocation + "\\..\\Images\\q.jpg"))
		return false;
	if (!textures.king.Load(programLocation + "\\..\\Images\\k.jpg"))
		return false;


	// Setup the board.
	Piece tempPiece;
	tempPiece.type = TYPE_PAWN;
	tempPiece.player = PLAYER_BLACK;	

	// Setup pawns.
	for (int i = 0; i < globals.BOARD_WIDTH; i++)	
		board.pieces[i][1] = tempPiece;
	
	tempPiece.player = PLAYER_WHITE;

	for (int i = 0; i < globals.BOARD_WIDTH; i++)	
		board.pieces[i][6] = tempPiece;

	// Setup Rooks.
	tempPiece.player = PLAYER_BLACK;
	tempPiece.type = TYPE_ROOK;

	board.pieces[0][0] = tempPiece;
	board.pieces[7][0] = tempPiece;

	tempPiece.player = PLAYER_WHITE;

	board.pieces[0][7] = tempPiece;
	board.pieces[7][7] = tempPiece;

	// Setup Bishops.
	tempPiece.player = PLAYER_BLACK;
	tempPiece.type = TYPE_BISHOP;

	board.pieces[1][0] = tempPiece;
	board.pieces[6][0] = tempPiece;

	tempPiece.player = PLAYER_WHITE;

	board.pieces[1][7] = tempPiece;
	board.pieces[6][7] = tempPiece;

	// Setup Knights.
	tempPiece.player = PLAYER_BLACK;
	tempPiece.type = TYPE_KNIGHT;

	board.pieces[2][0] = tempPiece;
	board.pieces[5][0] = tempPiece;

	tempPiece.player = PLAYER_WHITE;

	board.pieces[2][7] = tempPiece;
	board.pieces[5][7] = tempPiece;

	// Setup Queens.
	tempPiece.player = PLAYER_BLACK;
	tempPiece.type = TYPE_QUEEN;

	board.pieces[3][0] = tempPiece;

	tempPiece.player = PLAYER_WHITE;

	board.pieces[4][7] = tempPiece;

	// Setup Kings.
	tempPiece.player = PLAYER_BLACK;
	tempPiece.type = TYPE_KING;

	board.pieces[4][0] = tempPiece;

	tempPiece.player = PLAYER_WHITE;

	board.pieces[3][7] = tempPiece;

	globals.currentPlayer = PLAYER_WHITE;	

	return true;	
}

void Shutdown()
{
	SDL_DestroyRenderer(globals.renderer);
	globals.renderer = nullptr;
	SDL_DestroyWindow(globals.window);
	globals.window = nullptr;
	SDL_Quit();
}
#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <string>

#include "Globals.h"

class Texture
{
public:	
	~Texture();

	void Clear();
	bool Load(std::string fileLoc);

	SDL_Texture* Get();
	SDL_Rect Rect() { return rect; };

private:
	SDL_Texture* tex;
	SDL_Rect rect;
};

Texture::~Texture()
{
	Clear();
}

void Texture::Clear()
{
	if (tex != nullptr)
		SDL_DestroyTexture(tex);

	tex = nullptr;
}

bool Texture::Load(std::string fileLoc)
{
	SDL_Surface* surface;

	// Use base SDL_Image loadign function
	surface = IMG_Load(fileLoc.c_str());

	if (surface == nullptr)
		return false;

	// Setup the default source rect
	rect.x = 0;
	rect.y = 0;
	rect.w = surface->w;
	rect.h = surface->h;

	// Set the color key for transparency as RGB(255, 0 , 255)
	SDL_SetColorKey(surface, true, SDL_MapRGB(surface->format, 255, 255, 255));

	// Create the new texture
	tex = SDL_CreateTextureFromSurface(globals.renderer, surface);

	// Clear out the old surface
	SDL_FreeSurface(surface);

	if (tex == nullptr)
		return false;

	return true;	
}

SDL_Texture* Texture::Get()
{
	return tex;
}


class Textures
{
private:
	

public:
	void Cleanup();



	Texture pawn;
	Texture rook;
	Texture knight;
	Texture bishop;
	Texture queen;
	Texture king;
}textures;

void Textures::Cleanup()
{
	pawn.Clear();
	rook.Clear();
	knight.Clear();
	bishop.Clear();
	queen.Clear();
	king.Clear();
}

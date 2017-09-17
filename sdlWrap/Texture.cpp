//
// Created by dario on 07/09/17.
//

#include <SDL_image.h>
#include <iostream>
#include "Texture.hpp"

namespace sdl
{

const char unknow[] ={"Unknow error!"};

std::vector<SDL_Rect> computeTiles(SDL_Rect &dim, const unsigned int tilesX, const unsigned int tilesY)
{
	// Variabili
	std::vector<SDL_Rect> tiles = std::vector<SDL_Rect>(tilesX*tilesY);

	dim.w /= tilesX;
	dim.h /= tilesY;

	for(unsigned int y = 0, i = 0; y < tilesY; y++)
		for(unsigned int x = 0; x < tilesX; x++, i++)
		{
			tiles[i].y = y * dim.h;
			tiles[i].x = x * dim.w;
			tiles[i].w = dim.w;
			tiles[i].h = dim.h;
		}

	return tiles;
}


/*Texture::Texture()
{
	std::clog << "Fake constructor called\n";
}*/


Texture::Texture(const Texture &source):
refParent(source.refParent)
{
	position = source.position;
	internalTexture = source.internalTexture;
	instances = source.instances;
	frames = source.frames;

	(*instances)++;
}

Texture::Texture(SDL_Surface *const surface, const Window &parent, const unsigned int tilesX, const unsigned int tilesY):
refParent(parent)
{
	SDL_SetError(unknow);

	if(!surface)
		throw sdl::Exception("surface was nullptr!", __LINE__-1, __FILE__);

	internalTexture = SDL_CreateTextureFromSurface(parent.getRenderer(), surface);

	if(!internalTexture)
		throw sdl::Exception(SDL_GetError(), __LINE__-3, __FILE__);

	SDL_QueryTexture(internalTexture, nullptr, nullptr,&position.w, &position.h);
	frames = computeTiles(position, tilesX, tilesY);

	instances = new unsigned long long(1);
}

Texture::Texture(const char *const file, const Window &parent, const unsigned int tilesX, const unsigned int tilesY):
refParent(parent)
{
	SDL_SetError(unknow);

	if(!file)
		throw sdl::Exception("file name was nullptr!", __LINE__-1, __FILE__);

	internalTexture = IMG_LoadTexture(parent.getRenderer(), file);

	if(!internalTexture)
		throw sdl::Exception(SDL_GetError(), __LINE__-1, __FILE__);

	SDL_QueryTexture(internalTexture, nullptr, nullptr,&position.w, &position.h);
	frames = computeTiles(position, tilesX, tilesY);

	instances = new unsigned long long(1);
}

Texture::~Texture()
{
	(*instances)--;// NULLPTR ???

	if(*instances)
		return;

	SDL_DestroyTexture(this->internalTexture);
	delete instances;
	instances = nullptr;
}

const Dimension &Texture::getPosition() const
{
	return position;
}

bool Texture::operator==(const Texture &rhs) const
{
	return internalTexture == rhs.internalTexture;
}

bool Texture::operator!=(const Texture &rhs) const
{
	return !(rhs == *this);
}

SDL_Texture * const Texture::getTexture()
{
	return internalTexture;
}

const SDL_Texture * const Texture::getTexture() const
{
	return internalTexture;
}

const Window &Texture::getParent() const
{
	return Texture::refParent;
}

unsigned long Texture::getFrame() const
{
	return frame;
}

void Texture::setFrame(unsigned long frame)
{
	Texture::frame = frame;
}

const SDL_Rect Texture::getFrameBounds() const
{
	return frames[frame];
}

unsigned long Texture::getFramesCount() const
{
	return frames.size();
}

const Anchor Texture::getAnchor() const
{
	return anchor;
}

void Texture::setAnchor(const u_int8_t x, const u_int8_t y)
{
	anchor.x = x;
	anchor.y = y;

	setPosition(position.originX, position.originY);
}

const u_int8_t maxValue = -1;
void Texture::setPosition(const int x, const int y)
{
	position.x = x - (anchor.x*position.w)/maxValue;
	position.y = y - (anchor.x*position.h)/maxValue;

	position.originX = x;
	position.originY = y;
}

}
//
// Created by dario on 07/09/17.
//

#ifndef TESTSDL_TEXTURE_HPP
#define TESTSDL_TEXTURE_HPP

#include <SDL2/SDL.h>
#include <vector>

#include "sdlWrap.hpp"

namespace sdl
{

class Window;

struct Anchor
{
	u_int8_t x = 0;
	u_int8_t y = 0;
};

struct Dimension: public SDL_Rect
{
	Dimension() { x = 0; y = 0; w = 0; h = 0; };
	int originX = 0;
	int originY = 0;
};

class Texture
{
public:
	Texture(const char * const file, const Window& parent, const unsigned int tilesX = 1, const unsigned int tilesY = 1);
	Texture(SDL_Surface * const surface, const Window& parent, const unsigned int tilesX = 1, const unsigned int tilesY = 1);
	Texture(const Texture& source);
	Texture() = delete;
	~Texture();

	const Dimension &getPosition() const;
	SDL_Texture * const getTexture();
	const SDL_Texture * const getTexture() const;
	const Window &getParent() const;
	unsigned long getFrame() const;
	unsigned long getFramesCount() const;
	const SDL_Rect getFrameBounds() const;
	const Anchor getAnchor() const;
	//const SDL

	void setPosition(const int x, const int y);
	void setFrame(const unsigned long frame);
	void setAnchor(const u_int8_t x, const u_int8_t y);

	bool operator==(const Texture &rhs) const;
	bool operator!=(const Texture &rhs) const;

private:
	SDL_Texture *internalTexture = 0;
	Dimension position;
	Anchor anchor = {0};

	std::vector<SDL_Rect> frames;
	unsigned long frame = 0;

	unsigned long long *instances = nullptr;
	const Window &refParent;

};

std::list<Texture*> coverArea(const Texture& instance, const SDL_Rect &area);
std::list<Texture*> coverArea(const Texture& instance, const int x, const int y, const unsigned int width, const unsigned int height);

void destroyAreaList(std::list<Texture*> &tiles);
}


#endif //TESTSDL_TEXTURE_HPP

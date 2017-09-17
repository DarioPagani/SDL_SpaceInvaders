//
// Created by dario on 12/09/17.
//

#ifndef TESTSDL_FONT_HPP
#define TESTSDL_FONT_HPP

#include "../sdlWrap.hpp"
#include "SDL2/SDL_ttf.h"

namespace sdl
{

class Font
{
public:
	Font() = delete;
	Font(const std::string &file, const int size) throw();
	Font(const Font &toCopy) = delete;
	~Font();

	Texture convertStr(Window &ref, const std::string &str, const SDL_Color &color = { 255, 255, 255, 255 }) throw();

private:
	TTF_Font *font = nullptr;
};

}


#endif //TESTSDL_FONT_HPP

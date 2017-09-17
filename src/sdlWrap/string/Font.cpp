//
// Created by dario on 12/09/17.
//

#include <iostream>
#include "Font.hpp"

namespace sdl
{
Font::Font(const std::string &file, const int size) throw()
{
	font = TTF_OpenFont(file.c_str(), size);

	if(!font)
		throw Exception("Impossible load font!", __LINE__-3, __FILE__);
}

Font::~Font()
{
	if(isRunning())
		TTF_CloseFont(font);
}

Texture Font::convertStr(Window &ref, const std::string &str, const SDL_Color &color) throw()
{
	SDL_Surface *gao = TTF_RenderText_Blended(font, str.c_str(), color);
	Texture ret(gao, ref);

	SDL_FreeSurface(gao);
	return ret;
}

}
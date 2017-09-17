//
// Created by dario on 06/09/17.
//

#ifndef TESTSDL_UTILS_HPP
#define TESTSDL_UTILS_HPP

#include <SDL2/SDL.h>

namespace utilis
{

void logConsole(std::ostream &ostream, const std::string &logMessage);
void logConsole(std::ostream &ostream, const char *const logMessage);
void logConsole(const std::string &logMessage);
void logConsole(const char *const logMessage);

SDL_Texture *loadTexure(const char *const file, SDL_Renderer *const render);

void renderTexture(SDL_Texture * const toRender, SDL_Renderer * const renderer, const int x, const int y, const int w, const int h);
void renderTexture(SDL_Texture * const toRender, SDL_Renderer * const renderer, const int x, const int y);

}

#endif //TESTSDL_UTILS_HPP

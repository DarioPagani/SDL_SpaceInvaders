//
// Created by dario on 07/09/17.
//

#ifndef TESTSDL_SDLWRAP_HPP
#define TESTSDL_SDLWRAP_HPP

#pragma GCC diagnostic ignored "-Wreorder"

namespace sdl
{
class Exception;

class Window;

class Texture;

int init() throw();
void dispose();
bool isRunning();

}

#include "Exception.hpp"
#include "Window.hpp"
#include "Texture.hpp"

#endif //TESTSDL_SDLWRAP_HPP

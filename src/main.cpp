#include <iostream>
#include "sdlWrap/sdlWrap.hpp"

#include "sdlWrap/string/Font.hpp"
#include "game/game.hpp"

int main()
{
	sdl::init();

	game::invaders::Invaders invaders;
	int ret = invaders.run();

	sdl::dispose();
	return ret;
}
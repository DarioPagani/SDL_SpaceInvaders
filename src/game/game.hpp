//
// Created by dario on 12/09/17.
//

#include "../sdlWrap/Window.hpp"
#include "../sdlWrap/string/Font.hpp"
#include "../physicSystem/SolidObject.hpp"

#ifndef TESTSDL_GAME_HPP
#define TESTSDL_GAME_HPP

#define WIDTH 160
#define HEIGTH 144

namespace game
{
namespace invaders
{

class Invaders
{
public:
	Invaders();
	int run();

private:
	sdl::Window		gioco;
	sdl::Font		font;
	sdl::Texture	button;
	SDL_Surface		*sfondoNero = SDL_CreateRGBSurface(0,WIDTH, HEIGTH, 32, 0,0,0,0x000000ff);
	sdl::Texture	textureSfondo;
	sdl::Texture	playerTexture;
	sdl::Texture	enemySheet;

	sdl::Texture	playerBullet;
	sdl::Texture	enemyBullet;

	std::list<physic::SolidObject*> enemies;
};

}
}

#endif //TESTSDL_GAME_HPP

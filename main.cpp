#include <iostream>
#include <SDL2/SDL.h>

#include "sdlWrap/sdlWrap.hpp"

#include "physicSystem/Object.hpp"
#include "physicSystem/SolidObject.hpp"
#include "sdlWrap/string/Font.hpp"
#include "game/game.hpp"

#define WIDTH 160
#define HEIGTH 144


class collision: public physic::solidObject::CollisionHandler
{
public:
	std::list<physic::SolidObject*> *enemies = nullptr;
	sdl::Window *window = nullptr;

	void onScreenBound(physic::SolidObject &source, const unsigned short side) override
	{
		if(side & BORDER_BOT)
			window->dispose();

		if(!enemies /*|| !(side & BORDER_HORIZONT)*/)
			return;

		for(auto i = enemies->begin(); i != enemies->end(); i++)
		{
			physic::Speed vel = (*i)->getSpeed();

			vel.x *=-1;
			(*i)->setSpeed(vel);
		}
	}
};

class windowHandler: public sdl::window::EventHandler
{
public:
	std::list<physic::SolidObject*> *enemies = nullptr;

	void onQuit(sdl::Window &source, const SDL_QuitEvent &quitEvent) override
	{
		source.dispose();
	}

	void onKey(sdl::Window &source, const SDL_KeyboardEvent &where) override
	{
		if(where.keysym.sym != SDLK_SPACE)
			return;

		source.dispose();

		/*std::cout << enemies->size() <<" Porca misera!\n";
		enemies->remove(*(enemies->begin()));

		for(auto i = enemies->begin(); i != enemies->end(); i++)
			(*i)->setAnchor(0x7F,0X7F);*/
	}
} close;

int main()
{
	sdl::init();
	game::invaders::Invaders gioco;

	int ret = gioco.run();

	sdl::dispose();

	return ret;
}
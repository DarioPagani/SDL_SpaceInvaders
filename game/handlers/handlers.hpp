//
// Created by dario on 15/09/17.
//

#ifndef TESTSDL_HANDLERS_HPP
#define TESTSDL_HANDLERS_HPP

#include <chrono>

#include "../../physicSystem/Object.hpp"
#include "../../physicSystem/SolidObject.hpp"

#include "../../physicSystem/CollisionHandler.hpp"

#define RICARICA 250

using namespace std::chrono;

class collision: public physic::solidObject::CollisionHandler
{
public:
	std::list<physic::SolidObject*> *enemies = nullptr;

	void onScreenBound(physic::SolidObject &source, const unsigned short side) override;
};

class exitHanlder: public sdl::window::EventHandler
{
public:
	void onQuit(sdl::Window &source, const SDL_QuitEvent &quitEvent) override { source.dispose(); }
	void onKey(sdl::Window &source, const SDL_KeyboardEvent &where) override;

private:
	SDL_Rect oldPos;
};

class menuHandler: public exitHanlder
{
public:
	bool timeToGo() { return pressed; };
	void onKey(sdl::Window &source, const SDL_KeyboardEvent &where) override;

private:
	bool pressed = 0;
};

class gameHandler: public exitHanlder, physic::solidObject::CollisionHandler
{
public:
	std::list <physic::SolidObject *> *proiettili = nullptr;
	physic::SolidObject *giocatore = nullptr;
	sdl::Texture *playerBullet = nullptr;
	std::list<physic::SolidObject*> *enemies = nullptr;

	void onObjectBound(physic::SolidObject &source, const physic::Object &collision) override;
	void keys(sdl::Window &source, const Uint8 *keys) override;
	void clean();

private:
	std::list<physic::SolidObject*> toDel;
	std::list<physic::SolidObject*> toDelP;
	high_resolution_clock::time_point lastShoot = high_resolution_clock::now();
};



#endif //TESTSDL_HANDLERS_HPP

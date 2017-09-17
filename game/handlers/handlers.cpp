//
// Created by dario on 15/09/17.
//

#include "handlers.hpp"
#include <algorithm>
#include <iostream>
#include "../game.hpp"


void collision::onScreenBound(physic::SolidObject &source, const unsigned short side)
{
	if(!enemies /*|| !(side & BORDER_HORIZONT)*/)
		return;

	for(auto i = enemies->begin(); i != enemies->end(); i++)
	{
		physic::Speed vel = (*i)->getSpeed();

		vel.x *=-1;
		(*i)->setSpeed(vel);
	}
}

void gameHandler::onObjectBound(physic::SolidObject &source, const physic::Object &collision)
{
	if(std::find(enemies->begin(), enemies->end(), &(physic::SolidObject &)collision) == enemies->end())
		return;

	if(std::find(toDelP.begin(), toDelP.end(), &source) == toDelP.end())
		toDelP.push_back(&source);

	if(std::find(toDel.begin(), toDel.end(), &(physic::SolidObject &)collision) == toDel.end())
		toDel.push_back(&(physic::SolidObject &)collision);
}

void gameHandler::keys(sdl::Window &source, const Uint8 *keys)
{
	if(keys[SDL_SCANCODE_SPACE] && ((lastShoot + milliseconds(RICARICA)) < high_resolution_clock::now()))
	{
		physic::SolidObject *sparo = new physic::SolidObject(*playerBullet, playerBullet->getPosition().w,
															 playerBullet->getPosition().h);
		sparo->setAnchor(0x7F, 0x7F);
		sparo->setPosition(giocatore->getPosition().x + giocatore->getPosition().w/2, giocatore->getPosition().y);
		sparo->setSpeed(0, -60);
		sparo->setHandler(this);
		proiettili->push_back(sparo);

		lastShoot = high_resolution_clock::now();
	}

	if(keys[SDL_SCANCODE_LEFT])
	{
		physic::Point dove = giocatore->getHighResolutionPosition();
		if(dove.x >= 0)
		{
			dove.x--;
			giocatore->setPosition(dove);
		}
	}

	if(keys[SDL_SCANCODE_RIGHT])
	{
		physic::Point dove = giocatore->getHighResolutionPosition();
		if(dove.x <= WIDTH)
		{
			dove.x++;
			giocatore->setPosition(dove);
		}
	}

}

void gameHandler::clean()
{
	for (auto &i : toDel)
	{
		enemies->remove(i);
		delete i;
	}

	for (auto &cmake-build-debugi : toDelP)
	{
		proiettili->remove(i);
		delete i;
	}

	toDelP.clear();
	toDel.clear();
}

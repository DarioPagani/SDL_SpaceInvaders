//
// Created by dario on 08/09/17.
//

#include <iostream>
#include <map>
#include "Object.hpp"
#include "SolidObject.hpp"
#include "CollisionHandler.hpp"

namespace physic
{
solidObject::CollisionHandler fake;
std::map<unsigned long long, std::list<SolidObject*>*> collisonMemory;
unsigned long long idGen = 0;

void SolidObject::update()
{
	// Variabili
	Object::update();
	SDL_Rect size = getTexture().getParent().getRenderDimension();

	unsigned short sides = 0;


	if((highRes.x + hitbox.x) <= 0)
		sides |= BORDER_LEFT;

	if((highRes.x + hitbox.x + hitbox.w) >= size.w)
		sides |= BORDER_RIGHT;

	if((highRes.y + hitbox.y) <= 0)
		sides |= BORDER_TOP;

	if((highRes.y + hitbox.y + hitbox.h) >= size.h)
		sides |= BORDER_BOT;

	if(sides)
		handler->onScreenBound(*this, sides);

	for(auto i = refToMapList->begin(); i != refToMapList->end(); i++)
		if(handler && *i != this && ((*i) -> isColliding(*this)))
			handler->onObjectBound(*this, **i);

}

void SolidObject::addToList()
{
	// Variabili
	auto coppia = collisonMemory.find(getTexture().getParent().getID());

	if(coppia == collisonMemory.end())
	{
		refToMapList = new std::list<SolidObject *>();
		collisonMemory.insert(std::make_pair(id, refToMapList));
	}
	else
		refToMapList = coppia->second;

	refToMapList->push_front(this);
}

SolidObject::SolidObject(const sdl::Texture &texture, const SDL_Rect &hitbox):
Object::Object(texture),
id(idGen++),
handler(&fake)
{
	SolidObject::hitbox = hitbox;
	addToList();
}

SolidObject::SolidObject(const sdl::Texture &texture, const int hitboxWidth, const int hitboxHeight,
						 const int hitboxOffsetX, const int hitboxOffsetY):
Object::Object(texture),
id(idGen++),
handler(&fake)
{
	SDL_Rect x = {0};
	x.w = hitboxWidth;
	x.h = hitboxHeight;
	x.x = hitboxOffsetX;
	x.y = hitboxOffsetY;

	SolidObject::hitbox = x;

	addToList();
}

void SolidObject::setHandler(solidObject::CollisionHandler * const handler)
{
	SolidObject::handler = handler;
}

SolidObject::SolidObject(const SolidObject &toCopy):
Object::Object(toCopy.getTexture()),
id(idGen++)
{
	std::cout << "ID in copia è: " << id << '\n';
	SolidObject::hitbox = toCopy.hitbox;
	*(SolidObject::handler) = *(toCopy.handler);
	SolidObject::refToMapList = toCopy.refToMapList;

	addToList();
}

SolidObject::~SolidObject()
{
	refToMapList->remove(this);

	if(refToMapList->empty())
	{
		delete refToMapList;
		refToMapList = nullptr;
	}
}

unsigned short SolidObject::isColliding(const SolidObject &other)
{
	unsigned short sides = 0b0;
	if((highRes.x + hitbox.x) > (other.highRes.x + other.hitbox.x + other.hitbox.w) )
		sides |= BORDER_TOP;

	if ((other.highRes.x + other.hitbox.x) > (highRes.x + hitbox.x + hitbox.w))
		sides |= BORDER_BOT;

	if((highRes.y + hitbox.y) > (other.highRes.y + other.hitbox.y + other.hitbox.h))
		sides |= BORDER_LEFT;

	if((other.highRes.y + other.hitbox.y) > (highRes.y + hitbox.y + hitbox.h))
		sides |= BORDER_RIGHT;

	return !sides;

}

sdl::Window &operator<<(sdl::Window &os, std::list<SolidObject *> &renders)
{
	for(auto i = renders.begin(); i != renders.end(); i++)
		os << (*i)->texture;


	return os;
}

bool segmentIsIntersect(const Point &segAStart, const Point &segAEnd, const Point &segBStart, const Point &segBEnd)
{
	return 0;
}

}
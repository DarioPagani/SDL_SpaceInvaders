//
// Created by dario on 08/09/17.
//

#ifndef TESTSDL_SOLIDOBJECT_HPP
#define TESTSDL_SOLIDOBJECT_HPP

#include "Object.hpp"
#include "CollisionHandler.hpp"


namespace physic
{
//namespace solidObject{class CollisionHandler;}
class SolidObject: public physic::Object
{
public:
	SolidObject(const sdl::Texture &texture, const SDL_Rect &hitbox = {0});
	SolidObject(const sdl::Texture &texture, const int hitboxWidth, const int hitboxHeight, const int hitboxOffsetX = 0,
				const int hitboxOffsetY = 0);
	SolidObject() = delete;
	SolidObject(const SolidObject &toCopy);
	virtual ~SolidObject();

	unsigned short isColliding(const SolidObject &other);

	void update();
	void setHandler(solidObject::CollisionHandler *handler);

	friend sdl::Window &operator<<(sdl::Window &os, std::list<SolidObject*> &renders);

private:
	SDL_Rect hitbox;
	solidObject::CollisionHandler *handler;
	const unsigned long long id;

	void addToList();
	std::list<SolidObject*>* refToMapList = nullptr;
};

}

#endif //TESTSDL_SOLIDOBJECT_HPP

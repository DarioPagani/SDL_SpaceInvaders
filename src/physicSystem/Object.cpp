//
// Created by dario on 08/09/17.
//

#include <iostream>
#include <cmath>

#include "Object.hpp"

namespace physic
{

Object::Object(const sdl::Texture &texturePtr):
texture(texturePtr)
{
	;
}

const sdl::Texture &Object::getTexture() const
{
	return texture;
}

/*void Object::setTexture(const sdl::Texture &texture)
{
	this->texture = texture;
}*/

unsigned short Object::getLayer() const
{
	return layer;
}

void Object::setLayer(unsigned short layer)
{
	Object::layer = layer;
}

const high_resolution_clock::time_point &Object::getLastCheck() const
{
	return lastCheck;
}

const Speed &Object::getSpeed() const
{
	return speed;
}

void Object::setSpeed(const Speed &speed)
{
	Object::speed = speed;
}

void Object::setSpeed(const double &xSpeed, const double &ySpeed)
{
	setSpeed({xSpeed, ySpeed});
}

bool Object::isColliding(const Object &other)
{
	return false;
}

void Object::update()
{
	auto timeMillis = std::chrono::duration_cast<std::chrono::milliseconds>(high_resolution_clock::now() - lastCheck);
	lastCheck = high_resolution_clock::now();
	//syncPos();

	highRes.x = highRes.x + (speed.x * timeMillis.count())/(double)1000;
	highRes.y = highRes.y + (speed.y * timeMillis.count())/(double)1000;

	texture.setPosition(std::round(highRes.x), std::round(highRes.y));
}

sdl::Window &operator<<(sdl::Window &os, Object &render)
{
	os << (render.texture);
	return os;
}

sdl::Window &operator<<(sdl::Window &os, std::list<Object *> &render)
{
	for(auto i = render.begin(); i != render.end(); i++)
		os << (*i)->texture;

	return os;
}

void Object::syncPos()
{
	const SDL_Rect &pos = texture.getPosition();

	if(abs(highRes.x - pos.x) > 2)
		highRes.x = pos.x;

	if(abs(highRes.y - pos.y) > 2)
		highRes.y = pos.y;
}

const Point &Object::getHighResolutionPosition() const
{
	return highRes;
}

const SDL_Rect &Object::getPosition() const
{
	return texture.getPosition();
}

void Object::setPosition(const double &x, const double &y)
{
	highRes.x = x;
	highRes.y = y;

	texture.setPosition(std::round(x), std::round(y));
}

void Object::setPosition(const int &x, const int &y)
{
	setPosition((double)x,(double)y);
}

void Object::setPosition(const Point &pos)
{
	highRes = pos;

	texture.setPosition(pos.x, pos.y);
}

const u_int8_t maxValue = -1;
void Object::setAnchor(const u_int8_t x, const u_int8_t y)
{
	texture.setAnchor(x,y);

	highRes.x = texture.getPosition().x;
	highRes.y = texture.getPosition().y;
}


}
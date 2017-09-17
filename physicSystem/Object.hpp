//
// Created by dario on 08/09/17.
//

#ifndef TESTSDL_OBJECT_HPP
#define TESTSDL_OBJECT_HPP

#include <chrono>
#include "../sdlWrap/sdlWrap.hpp"

namespace physic
{

using std::chrono::high_resolution_clock ;

struct Speed
{
	/**Speeds are expressed in pixels/seconds*/
	double x = 0;
	/**Speeds are expressed in pixels/seconds*/
	double y = 0;
};

struct Point
{
	double x = 0;
	double y = 0;
};

class Object
{
public:
	Object(const sdl::Texture &texture);
	Object() = delete;

	virtual bool isColliding(const Object& other);

	const sdl::Texture &getTexture() const;

	//void setTexture(const sdl::Texture &texture);

	unsigned short getLayer() const;
	void setLayer(unsigned short layer);

	const high_resolution_clock::time_point &getLastCheck() const;

	const Speed &getSpeed() const;
	const Point &getHighResolutionPosition() const;
	const SDL_Rect &getPosition() const;

	void setSpeed(const Speed &speed);
	void setSpeed(const double &xSpeed, const double &ySpeed);

	void setPosition(const int &x, const int& y);
	void setPosition(const double &x, const double &y);
	void setPosition(const Point &pos);

	void update();

	friend sdl::Window &operator<<(sdl::Window &os, Object &render);
	friend sdl::Window &operator<<(sdl::Window &os, std::list<Object*> &renders);

	void setAnchor(const u_int8_t x, const u_int8_t y);

protected:
	void syncPos();
	Point highRes = {0};
	sdl::Texture texture;

private:
	unsigned short layer = 0;
	high_resolution_clock::time_point lastCheck = high_resolution_clock::now();
	Speed speed = {0};
};

}


#endif //TESTSDL_OBJECT_HPP

//
// Created by dario on 08/09/17.
//

#ifndef TESTSDL_COLLISIONHANDLER_HPP
#define TESTSDL_COLLISIONHANDLER_HPP

#include "SolidObject.hpp"

#define BORDER_TOP		0b0001
#define BORDER_RIGHT	0b0010
#define BORDER_BOT		0b0100
#define BORDER_LEFT		0b1000

#define BORDER_VERTICAL	(BORDER_LEFT | BORDER_RIGHT)
#define BORDER_HORIZONT	(BORDER_TOP  | BORDER_BOT)

namespace physic
{
class SolidObject;

namespace solidObject
{

class CollisionHandler
{
public:
	virtual void onScreenBound(SolidObject &source, const unsigned short side){};
	virtual void onObjectBound(SolidObject &source, const Object &collision){};
};

}

}

#endif //TESTSDL_COLLISIONHANDLER_HPP

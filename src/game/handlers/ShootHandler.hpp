//
// Created by dario on 17/09/17.
//

#ifndef SPACEINVADERS_SHOOTHANDLER_HPP
#define SPACEINVADERS_SHOOTHANDLER_HPP


#include "../../physicSystem/SolidObject.hpp"
using namespace std::chrono;

class ShootHandler
{
public:
	std::list <physic::SolidObject *> *enemies = nullptr;
	std::list <physic::SolidObject *> *proiettili = nullptr;


	void shoot();

private:
	high_resolution_clock::time_point lastShoot = high_resolution_clock::now();

};


#endif //SPACEINVADERS_SHOOTHANDLER_HPP

//
// Created by dario on 17/09/17.
//

#include <iostream>
#include "ShootHandler.hpp"
#include "../settings.hpp"

void ShootHandler::shoot()
{
	if(enemies->empty() || ((lastShoot + SHOOT_TIMING_ENEMY) >= high_resolution_clock::now()))
		return;

	lastShoot = high_resolution_clock::now();
}

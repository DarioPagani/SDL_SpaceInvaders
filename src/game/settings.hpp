//
// Created by dario on 17/09/17.
//

#ifndef SPACEINVADERS_SETTINGS_HPP
#define SPACEINVADERS_SETTINGS_HPP


#define WIDTH					160
#define HEIGTH					144

#define WINDOW_BASE_WIDTH		WIDTH * 4
#define WINDOW_BASE_HEIGHT		HEIGTH * 4
//#define WINDOW_IS_FULLSCREEN	true

#define SHOOT_TIMING_PLAYER		std::chrono::milliseconds(250)
#define SHOOT_TIMING_ENEMY		std::chrono::milliseconds(1300)

#define PLAYER_LIFES			3
#define PLAYER_BULLET_SPEED		-60

#define ENEMY_DESCENDING_SPEED	1
#define ENEMY_MOVING_SPEED		5

#endif //SPACEINVADERS_SETTINGS_HPP

//
// Created by dario on 12/09/17.
//

#include <iostream>
#include <algorithm>
#include "game.hpp"
#include "handlers/handlers.hpp"
#include "handlers/ShootHandler.hpp"

namespace game
{
namespace invaders
{

// ROBA DELLA CLASSE
/** Create a Window with space invaders inside! **/
Invaders::Invaders():
gioco("SpaceInvadersAustrungarici", WINDOW_BASE_WIDTH, WINDOW_BASE_HEIGHT, WIDTH, HEIGTH),
font("./asset/sample.ttf", 12),
textureSfondo(sfondoNero, gioco),
playerTexture("./asset/spaceClonePlayer.png", gioco),
enemySheet("./asset/spaceCloneEnemies.png", gioco,4,1),
enemyBullet("./asset/spaceCloneBulletE.png",gioco),
playerBullet("./asset/spaceCloneBullet.png",gioco)
{
}

int Invaders::run()
{
	// Variabili
	sdl::Texture begingText(font.convertStr(gioco, "Press SPACE to Begin!"));
	begingText.setAnchor(0x7F, 0x7F);
	begingText.setPosition(WIDTH/2, HEIGTH/2);

	menuHandler wait;
	gameHandler gameHandler_t;
	std::list <physic::SolidObject *> proiettili;
	std::list <physic::SolidObject *> proiettiliNemici;
	physic::SolidObject giocatore(playerTexture, playerTexture.getPosition().w, playerTexture.getPosition().h);
	giocatore.setAnchor(0x7F, 0x7F);
	giocatore.setPosition(WIDTH/2,130);

	collision	collisionHandler;
	collisionHandler.enemies = &enemies;

	gameHandler_t.proiettili = &proiettili;
	gameHandler_t.playerBullet = &playerBullet;
	gameHandler_t.giocatore = &giocatore;
	gameHandler_t.enemies = &enemies;

	ShootHandler shootHandler;
	shootHandler.enemies = &enemies;
	shootHandler.proiettili = &proiettiliNemici;

	//gioco.setWindowFullscreen(WINDOW_IS_FULLSCREEN);
	gioco.setVisible(true);
	gioco.setHandler(&wait);

	while(!gioco.isQuitted() && !wait.timeToGo())
	{
		gioco.clearFrame();
		if(time(nullptr) % 2)
			gioco << begingText;

		gioco.paintFrame();
	}

	// Preparitivi
	for(unsigned int y = 0; y < 4; y++)
		for(unsigned int x = 0; x < 7; x++)
		{
			physic::SolidObject *nemico = new physic::SolidObject(enemySheet,16,16);
			const_cast<sdl::Texture &>(nemico->getTexture()).setFrame(y);
			nemico->setPosition((20.0*x) + 2*y + 10,1+20.0*y);
			nemico->setHandler(&collisionHandler);
			nemico->setSpeed(ENEMY_MOVING_SPEED,ENEMY_DESCENDING_SPEED);
			enemies.push_back(nemico);
		}

	gioco.setHandler(&gameHandler_t);

	while(!gioco.isQuitted() && !enemies.empty())
	{
		gioco.clearFrame();

		for (auto &i : proiettili)
			i->update();

		for (auto &enemie : enemies)
			enemie->update();

		giocatore.update();
		gameHandler_t.clean();
		shootHandler.shoot();

		gioco << enemies << proiettili << giocatore;
		gioco.paintFrame();
	}

	gioco.setVisible(false);

	// Pulire
	for(auto i = enemies.begin(); i != enemies.end(); i++)
		delete (*i);

	return 0;
}

}
}
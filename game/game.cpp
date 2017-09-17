//
// Created by dario on 12/09/17.
//

#include <iostream>
#include <algorithm>
#include "game.hpp"
#include "handlers/handlers.hpp"

namespace game
{
namespace invaders
{

// ROBA DELLA CLASSE
/** Create a Window with space invaders inside! **/
Invaders::Invaders():
gioco("SpaceInvadersAustrungarici", WIDTH*4, HEIGTH*4, WIDTH, HEIGTH),
font("./asset/sample.ttf", 12),
button(font.convertStr(gioco, "Press SPACE to Begin!")),
textureSfondo(sfondoNero, gioco),
playerTexture("./asset/spaceClonePlayer.png", gioco),
enemySheet("./asset/spaceCloneEnemies.png", gioco,4,1),
enemyBullet("./asset/spaceCloneBulletE.png",gioco),
playerBullet("./asset/spaceCloneBullet.png",gioco)
{
	button.setAnchor(0x7F, 0X7F);
	button.setPosition(WIDTH/2, HEIGTH/2);
}

int Invaders::run()
{
	// Variabili
	menuHandler wait;
	gameHandler gameHandler_t;
	std::list <physic::SolidObject *> proiettili;
	physic::SolidObject giocatore(playerTexture, playerTexture.getPosition().w, playerTexture.getPosition().h);
	giocatore.setAnchor(0x7F, 0x7F);
	giocatore.setPosition(WIDTH/2,130);

	collision	collisionHandler;
	collisionHandler.enemies = &enemies;

	gameHandler_t.proiettili = &proiettili;
	gameHandler_t.playerBullet = &playerBullet;
	gameHandler_t.giocatore = &giocatore;
	gameHandler_t.enemies = &enemies;

	//gioco.setWindowFullscreen(true);
	//gioco.setWindowDimension(1920, 1080);
	gioco.setVisible(true);
	gioco.setHandler(&wait);

	while(!gioco.isQuitted() && !wait.timeToGo())
	{
		gioco.clearFrame();
		if(time(nullptr) % 2)
			gioco << button;

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
			nemico->setSpeed(5,1);
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
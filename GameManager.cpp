#include "GameManager.h"
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <time.h>
#include <constream>
#include <conio.h>
#include "EnemyShip.h"

using namespace std;
using namespace conio;

GameManager::GameManager() {
	bulletPool = new BulletPool();
	formation = new Formation(bulletPool);
}

void GameManager::setupPlayer() {
	player = new Player();
	int playerPosition[2] = {75,57};
	
	player->setPosition(playerPosition);
}

void GameManager::gameLoop() { 
	setupPlayer();
	
	/* initialize random seed: */
	srand (time(NULL));
		
	// loop time management
	int ticks, lastRefresh;
	ticks = 60;
	
	lastRefresh = clock();
		
	while(true){
		if(clock() > lastRefresh + ticks) { 
			clrscr();			
			int strongShipDie = rand() % 50;
			int commonShipDie = rand() % 100;
			formation->updateBulletPool();
			if (strongShipDie % 3 == 0 && strongShipDie > 50) { 
				int index = rand() % 2;
				formation->makeStrongShipsAttack(index);
			}  
				
			if (commonShipDie % 3 == 0 && commonShipDie > 50) { 
				int x = rand() % 3 + 2;
				int y = rand() % 4;
				formation->makeCommonShipAttack(y, x);
			}
			
			int shootDie = rand() % 10;
			if (shootDie % 3 == 0) {
				formation->makeShipsShoot();
			}
			
			
			formation->handleStateAndUpdate();	
			
			lastRefresh = clock();
			
			if(kbhit())
			{
				char input = getch();
				switch(input)
				{
				case 'a':
					player->changeState(PlayerStates::MOVE_LEFT);	
					player->move();
					break;
				case 'd':
					player->changeState(PlayerStates::MOVE_RIGHT);
					player->move();
					break;
				case 'j':
					break;
				}				
			}
			
			player->draw();
		}
	}
};


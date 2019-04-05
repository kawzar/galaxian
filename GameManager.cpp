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
	formation = new Formation();
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
	int strongShipTicks, lastStrongShipAttack;
	strongShipTicks = 2000;
	lastRefresh = clock();
	lastStrongShipAttack = clock();
		
	while(true){
		if(clock() > lastRefresh + ticks) { 
			clrscr();
			formation->handleStateAndUpdate();			
			lastRefresh = clock();		
			
			if (clock() > lastStrongShipAttack + strongShipTicks) { 
				int index = rand() % 2;
				formation->makeStrongShipsAttack(index);
				lastStrongShipAttack = clock();
			}
			
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


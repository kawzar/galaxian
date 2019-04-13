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

GameManager::GameManager(const int windowSizeX, const int windowSizeY) {
	bulletPool = new BulletPool(windowSizeX, windowSizeY);
	formation = new Formation(bulletPool, windowSizeX, windowSizeY);
	gameLoop_ = true;
	windowX = windowSizeX;
	windowY = windowSizeY;
}

void GameManager::setupPlayer() {
	player = new Player(windowX, windowY);
	int playerPosition[2] = {windowX/2,windowY - 4};
	
	player->setPosition(playerPosition);
}

void GameManager::gameLoop() { 
	setupPlayer();
	
	// initialize random seed:
	srand (time(NULL));
		
	// loop time management
	int ticks, lastRefresh;
	ticks = 60;
	int strongShipTicks, lastStrongShipAttack;
	strongShipTicks = 7000;
	int commonShipTicks, lastCommonShipAttack;
	commonShipTicks = 2000;
	
	int shootTicks, lastShootRefresh;
	shootTicks = 100;
	
	lastRefresh = clock();
	lastStrongShipAttack = clock();
	lastCommonShipAttack = clock();
	lastShootRefresh = clock();
		
	while(gameLoop_){
		if(clock() > lastRefresh + ticks) { 
			clrscr();			
			
			
			if (clock() > lastStrongShipAttack + strongShipTicks) { 
				int index = rand() % 2;
				formation->makeStrongShipsAttack(index);
				lastStrongShipAttack = clock();
			}  
				
			if (clock() > lastCommonShipAttack + commonShipTicks) { 
				int x = rand() % 3 + 2;
				int y = rand() % 4;
				formation->makeCommonShipAttack(y, x);
				lastCommonShipAttack = clock();
			}
			
			if (clock() > lastShootRefresh + shootTicks) {
				formation->makeShipsShoot();
				lastShootRefresh = clock();
			}
			
			formation->handleStateAndUpdate();	
			formation->updateBulletPool();
			player->updateBulletPosition();
			formation->checkCollisions(player, player->getBullet());
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
					player->shoot();
					break;
				}				
			}
			
			player->draw();
			printScoreAndLife();
			
			if (player->getLife() <= 0 || formation->checkAllDead()) { 
				gameLoop_ = false;
			}
		}
	}
	
	printHighscores();
};

void GameManager::printScoreAndLife() { 
	gotoxy(5, windowY-1);
	textcolor(10);
	cout << "Score: " << formation->getScore();
	textcolor(15);
	cout << "--- ";
	textcolor(12);
	cout << "Lifes: " << player->getLife();
}

void GameManager::printHighscores() {
	clrscr();
	gotoxy(5, 2);
	textcolor(10);
	
	cout << "GAME OVER!" << endl;
	cout << "Score is: "<< formation->getScore();
	getchar();
}

void GameManager::introScreen() {
	textcolor(12);
	cout << "WE ARE GALAXIANS" << endl;
	
	textcolor(11);
	cout << "Mission: Destroy aliens" << endl;
	
	textcolor(14);
	cout << "Move: W A S D" << endl;
	cout << "Shoot: J" << endl;
	
	textcolor(11);
	cout << "Press ENTER" << endl;
	
	
	getchar();
}

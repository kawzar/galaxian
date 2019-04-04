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
}

void GameManager::setupFormation(){
	// initialize ships
	int newPosition[2] = {1,1};
	
	for (int i = 0; i < 2; i++) {		
		for (int j = 0; j < 5; j++) {
			formation[i][j] = new EnemyShip();
			int velocity[2] = {1, 0};
			newPosition[0] = newPosition[0] + 9;
			
			formation[i][j]->setPosition(newPosition);
			formation[i][j]->setVelocity(velocity);
		}
		newPosition[0] = 1;
		newPosition[1] = newPosition[1] + 4;
	}
}

void GameManager::setupPlayer() {
	player = new Player();
	int playerPosition[2] = {75,57};
	
	player->setPosition(playerPosition);
}

void GameManager::gameLoop() { 
	setupFormation();
	setupPlayer();
	
	// loop time management
	int ticks, lastRefresh;
	ticks = 60;
	lastRefresh = clock();
		
	while(true){
		if(clock() > lastRefresh + ticks) { 
			clrscr();
			moveFormation();
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
					//player->shoot();
					break;
				}				
			}
			
			player->draw();
		}
	}
};

void GameManager::moveFormation() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j< 5; j++) {
			if(formation[0][4]->getVelocity()[0] == 1 && formation[0][4]->getPosition()[0] + 9 >= 119) {
				int newVelocity [2] = {-1, 0};
				formation[i][j]->setVelocity(newVelocity);
			} else if (formation[0][0]->getVelocity()[0] == -1 && formation[0][0]->getPosition()[0]<= 1){ 
				int newVelocity [2] = {1, 0};
				formation[i][j]->setVelocity(newVelocity);
			}
				formation[i][j]->move();
				formation[i][j]->draw();
		}
	}
};


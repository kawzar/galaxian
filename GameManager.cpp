#include "GameManager.h"
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <time.h>
#include <constream>
#include <conio.h>

#ifndef GAMEMANAGER_H	#define	GAMEMANAGER_H	

using namespace std;
using namespace conio;

GameManager::GameManager() {
	strcpy(enemySprite[0], "   /\\");
	strcpy(enemySprite[1], "  (  )");
	strcpy(enemySprite[2], " /|/\\|\\");
}

void GameManager::gameLoop() { 
	// initialize ships
	int newPosition[2] = {1,1};
	
	for (int i = 0; i < 2; i++) {		
		for (int j = 0; j < 5; j++) {
			formation[i][j] = new Ship();
			int velocity[2] = {1, 0};
			newPosition[0] = newPosition[0] + 9;
			
			formation[i][j]->setColor(7);
			formation[i][j]->setPosition(newPosition);
			formation[i][j]->setSprite(enemySprite);
			formation[i][j]->setVelocity(velocity);
		}
		newPosition[0] = 1;
		newPosition[1] = newPosition[1] + 4;
	}
	
	// proper game loop
	int ticks, lastRefresh;
	ticks = 60;
	lastRefresh = clock();
	
	while(true){
		if(clock() > lastRefresh + ticks) { 
			clrscr();
			moveFormation();
			lastRefresh = clock();			
		}
	}
};

void GameManager::moveFormation() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j< 5; j++) {
			formation[i][j]->move();
			formation[i][j]->draw();
		}
	}
};

#endif

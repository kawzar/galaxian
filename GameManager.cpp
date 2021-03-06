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
	scoreManager = new ScoreManager();
}

GameManager::~GameManager() {
	delete bulletPool;
	delete formation;
	delete scoreManager;
	delete player;
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
	cout << " --- ";
	textcolor(12);
	cout << "Lifes: " << player->getLife();
}

void GameManager::printHighscores() {
	clrscr();
	gotoxy(2, 2);
	textcolor(10);
	int playerScore = formation->getScore() + player->getLife() * 100;
	
	cout << "GAME OVER!" << endl;
	cout << "Score is: "<< playerScore << endl;
	
	Score* highScores[5];
	scoreManager->getHighScores(highScores);
	bool isHighScore = false;
	for(int i = 0; i < 5 && !isHighScore; i++) { 
		if (highScores[i]->score <= playerScore) { 
			isHighScore = true;
		}
	}
	
	char name[30];
		
	if (isHighScore) { 
		cout << "You make it to the highscores! Please Enter your name:" << endl << endl;
		gets(name);
		cout << endl;
		Score* newScore = new Score();
		strcpy(newScore->name, name);
		newScore->score = playerScore;
		
		scoreManager->addScore(highScores, newScore, highScores);
	} 
	
	scoreManager->getHighScores(highScores);
	
	for (int i = 0; i < 5; i++) {
		textcolor(i +3);
		cout << "Score #" << i + 1 << endl;
		puts(highScores[i]->name);
		cout << highScores[i]->score << endl;
		cout << endl;
		
	}
	
	textcolor(8);
	cout << "Press ENTER to exit game" << endl;
	
	getchar();
}

void GameManager::introScreen() {
	textcolor(12);
	cout << "WE ARE GALAXIANS" << endl;
	
	textcolor(11);
	cout << "Mission: Destroy aliens" << endl;
	
	textcolor(14);
	cout << "Move: W A S D" << endl;
	cout << "Shoot: J" << endl << endl;
	
	textcolor(9);
	cout << "Alien ship: " << 100 << " points"<<endl;
	
	textcolor(14);
	cout << "Medium alien ship: " << 150 << " points" << endl;
	
	textcolor(13);
	cout << "Strong alien ship: " << 200 << " points" << endl;
	
	textcolor(12);
	cout << "You get extra points for every life left!" << endl << endl;
	
	textcolor(11);
	cout << "Press ENTER" << endl;	
	
	getchar();
}

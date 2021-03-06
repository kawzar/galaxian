#include "Formation.h"
#include <stdio.h>
#include <iostream>

using namespace std;

Formation::Formation(BulletPool* bulletPool, const int windowSizeX, const int windowSizeY){
	// initialize ships
	state = FormationStates::FORMATION_RIGHT;
	int newPosition[2] = {1,1};
	leftLimit = 5;
	bulletPool_ = bulletPool;
	score = 0;
	windowX = windowSizeX;
	windowY = windowSizeY;
	
	for (int i = 0; i < ySize; i++) {		
		for (int j = 0; j < xSize; j++) {
			if (i == 1) {
				formation[i][j] = new MediumEnemyShip(bulletPool, windowSizeX, windowSizeY);
			} else {
				formation[i][j] = new EnemyShip(bulletPool, windowSizeX, windowSizeY);
			}
			
			int velocity[2] = {1, 0};
			newPosition[0] = newPosition[0] + 9;
			rightLimit = newPosition[0] + 9;
			
			formation[i][j]->setPosition(newPosition);
			formation[i][j]->setFormationPosition(newPosition);
			formation[i][j]->setVelocity(velocity);
		}
		newPosition[0] = 1;
		newPosition[1] = newPosition[1] + 4;
	}
	
	// set left strong ship
	delete formation[0][1];
	formation[0][1] = new StrongEnemyShip((MediumEnemyShip*)formation[1][0], (MediumEnemyShip*)formation[1][2], 7, bulletPool, windowSizeX, windowSizeY);

	int velocity[2] = {1, 0};
	newPosition[0] = 19;
	newPosition[1] = 1;
	formation[0][1]->setPosition(newPosition);
	formation[0][1]->setFormationPosition(newPosition);
	formation[0][1]->setVelocity(velocity);
	
	// set right strong ship
	delete formation[0][3];
	formation[0][3] = new StrongEnemyShip((MediumEnemyShip*)formation[1][2], (MediumEnemyShip*)formation[1][4], 7, bulletPool, windowSizeX, windowSizeY);

	newPosition[0] = 19 + 9 + 9;
	newPosition[1] = 1;
	formation[0][3]->setPosition(newPosition);
	formation[0][3]->setFormationPosition(newPosition);
	formation[0][3]->setVelocity(velocity);
	
	formation[0][0]->setAlive(false);
	formation[0][2]->setAlive(false);
	formation[0][4]->setAlive(false);
	
	strongEnemyShips[0] = formation[0][1];
	strongEnemyShips[1] = formation[0][3];
}


Formation::~Formation() {
	for (int i = 0; i < ySize; i++) {		
		for (int j = 0; j < xSize; j++) {
			delete formation[i][j];
		}
	}
}

void Formation::handleStateAndUpdate(){	
	switch (state){
	case FORMATION_LEFT:
		leftLimit--;
		rightLimit--;
		if (leftLimit <= 1) {
			handleFormationStates(FormationStates::FORMATION_RIGHT);
		} else {
			handleFormationStates(state);
		}
		break;
	case FORMATION_RIGHT:
		leftLimit++;
		rightLimit++;
		if (rightLimit >= windowX) {
			handleFormationStates(FormationStates::FORMATION_LEFT);
		} else {
			handleFormationStates(state);
		}
		break;
	default:
		handleFormationStates(state);
		break;
	}
}

void Formation::handleFormationStates(FormationStates s){
	int velocityFormationPosition [2] = {1,0};
	for (int i = 0; i < ySize; i++) {
		for (int j = 0; j< xSize; j++) {
			if (formation[i][j]->isInFormation() && formation[i][j]->isAlive()){ 
				if (s == FORMATION_LEFT){
					formation[i][j]->handleStateAndUpdate(EnemyShipState::FORMATION_MOVING_LEFT);
					
					velocityFormationPosition[0] = -1;
					formation[i][j]->changeFormationPosition(velocityFormationPosition);
					state = FORMATION_LEFT;
				}
				else if (s == FORMATION_RIGHT){ 
					formation[i][j]->handleStateAndUpdate(EnemyShipState::FORMATION_MOVING_RIGHT);
					
					state = FORMATION_RIGHT;					
					velocityFormationPosition[0] = 1;
					formation[i][j]->changeFormationPosition(velocityFormationPosition);
				} 
			} else if(formation[i][j]->isAlive()) { 
				formation[i][j]->handleStateAndUpdate(EnemyShipState::ATTACKING_ALONE);
				// handle where to go back!
				if (s == FORMATION_LEFT){ 
					velocityFormationPosition[0] = -1;
				} else {
					velocityFormationPosition[0] = 1;
				}	
				
				formation[i][j]->changeFormationPosition(velocityFormationPosition);
			}
		}		
	}
}

void Formation::makeStrongShipsAttack(const int index) {
	strongEnemyShips[index]->handleStateAndUpdate(EnemyShipState::ATTACKING_ALONE);
}

void Formation::makeCommonShipAttack(const int x, const int y) {
	formation[x][y]->handleStateAndUpdate(EnemyShipState::ATTACKING_ALONE);
}
	
void Formation::makeShipsShoot() { 
	int xIndex = rand() % xSize;
	int yIndex = rand() % ySize;
	
	if (formation[yIndex][xIndex]->isAlive() && !formation[yIndex][xIndex]->isInFormation()) { 
		formation[yIndex][xIndex]->shoot();
	}
}

void Formation::updateBulletPool() {
	bulletPool_->update();
}

void Formation::checkCollisions(Player* player, Bullet* playerBullet) { 
	int* playerBulletPosition = playerBullet->getPosition();
	bool continueIterating = true;
	for (int i = 0; i < ySize && continueIterating; i++) {
		for (int j = 0; j< xSize && continueIterating; j++) {
			if (formation[i][j]->isAlive() && formation[i][j]->intersects(playerBulletPosition)){
				playerBullet->die();
				formation[i][j]->die();
				score += formation[i][j]->getPoints();
				continueIterating = false;
			}
		}
	}
	
	bulletPool_->checkCollisions(player);
}

int Formation::getScore() {
	return score;
}

bool Formation::checkAllDead() {
	bool allDead = true;
	
	for (int i = 0; i < ySize && allDead; i++) {
		for (int j = 0; j< xSize && allDead; j++) {
			if (formation[i][j]->isAlive()) { 
				allDead = false;
			}
		}
	}
	
	return allDead;
}

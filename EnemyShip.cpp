#include "EnemyShip.h"
#include <cstring>
#include <time.h>
using namespace std;

EnemyShip::EnemyShip(BulletPool* pool){
	char toDraw[3][8];
	strcpy(toDraw[0], "\\|\\/|/");
	strcpy(toDraw[1], " (  )");
	strcpy(toDraw[2], "  \\/");
	
	setSprite(toDraw);
	setColor(9);
	isInFormation_ = true;
	state = EnemyShipState::FORMATION_MOVING_RIGHT;
	
	ticks = 250;
	bulletPool = pool;
}

EnemyShip::~EnemyShip(){
	delete sprite;
}

void EnemyShip::handleStateAndUpdate(EnemyShipState s){
	if (s != state){
		state = s;
	}
	
	int velocity[2] = {1,0};
	
	switch(state) {
	case FORMATION_MOVING_LEFT:
		velocity[0] = -1;
		setVelocity(velocity);
		break;
	case FORMATION_MOVING_RIGHT:
		velocity[0] = 1;
		setVelocity(velocity);
		break;
	case ATTACKING_ALONE:
		if (isInFormation_){
			attack();
		} else { 
			int* position = getPosition();
			
			if (isAlive_ && (position[0] >= 117 || position[1] >= 50)) {
				goBackToFormation();
			}
			
			delete position;
		}
		break;
	}
	
	move();
	draw();
}

bool EnemyShip::isInFormation(){
	return isInFormation_;
}


void EnemyShip::attack() { 
	int* newPosition;
	int newVelocity[2] = {0, 1};
	
	newPosition = getPosition();
	newPosition[1] = yPosition;
	setPosition(newPosition);
	setVelocity(newVelocity);
	delete newPosition;
	isInFormation_ = false;
}

void EnemyShip::setAlive(const bool alive) { 
	isAlive_ = alive;
}


void EnemyShip::goBackToFormation() {
	int velocity[2] = {0,0};
	setPosition(formationPosition);
	setVelocity(velocity);
	state = EnemyShipState::FORMATION_MOVING_RIGHT;
	
	isInFormation_ = true;
}

void EnemyShip::setFormationPosition(const int position[2]){
	formationPosition[0] = position[0];
	formationPosition[1] = position[1];
}

void EnemyShip::changeFormationPosition(const int velocity[2]){
	formationPosition[0] = formationPosition[0] + velocity[0];
	formationPosition[1] = formationPosition[1] + velocity[1];
}

void EnemyShip::shoot() {
	int* bulletPos = getPosition();
	int newBulletPosition[2] = {0,0};
	newBulletPosition[1] = bulletPos[1] + 6;
	newBulletPosition[0] = bulletPos[0] + 2;
	
	bulletPool->create(newBulletPosition, bulletVelocity, sprite->getColor());
}

void EnemyShip::die() { 
	isAlive_ = false;
}

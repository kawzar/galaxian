#include "EnemyShip.h"
#include <cstring>
using namespace std;

EnemyShip::EnemyShip(){
	char toDraw[3][8];
	strcpy(toDraw[0], "\\|\\/|/");
	strcpy(toDraw[1], " (  )");
	strcpy(toDraw[2], "  \\/");
	
	setSprite(toDraw);
	setColor(10);
	isInFormation_ = true;
}

EnemyShip::~EnemyShip(){
	delete sprite;
}

void EnemyShip::handleStateAndUpdate(EnemyShipState s){
	EnemyShipState previous;
	if (s != state){
		previous = state;
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
		}
		break;
	case ATTACKING_GROUP:
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

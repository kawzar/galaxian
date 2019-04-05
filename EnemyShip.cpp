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
}

void EnemyShip::handleStateAndUpdate(EnemyShipState s){
	if (s != state){
		state = s;
	}
	
	int velocity[2] = {0,0};
	
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
		break;
	case ATTACKING_GROUP:
		break;
	}
}

bool EnemyShip::isAlive(){
	return isAlive_;
}

bool EnemyShip::isInFormation(){
	return isInFormation_;
}


void EnemyShip::attack() { 
	
}

void EnemyShip::setAlive(const bool alive) { 
	isAlive_ = alive;
}

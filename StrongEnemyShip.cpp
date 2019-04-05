#include "StrongEnemyShip.h"

StrongEnemyShip::StrongEnemyShip(MediumEnemyShip* l, MediumEnemyShip* r, const int yPos){
	left = l;
	right = r;
	yPosition = yPos;
}

void StrongEnemyShip::attack() {
	int* newPosition;
	int newVelocity[2] = {1, 0};
	
	if (left->isAlive() && left ->isInFormation()) { 
		newPosition = left->getPosition();
		newPosition[1] = yPosition;
		left->attack();
	}
	
	if (right-> isAlive() && right -> isInFormation()) {
		newPosition = right->getPosition();
		newPosition[1] = yPosition;
		right->attack();
	}
	
	newPosition = getPosition();
	newPosition[1] = yPosition;
	setPosition(newPosition);
	setVelocity(newVelocity);
	delete newPosition;
}

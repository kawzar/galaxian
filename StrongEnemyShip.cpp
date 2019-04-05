#include "StrongEnemyShip.h"

StrongEnemyShip::StrongEnemyShip(MediumEnemyShip* l, MediumEnemyShip* r, const int yPos) : EnemyShip(){
	left = l;
	right = r;
	yPosition = yPos;
	setColor(14);
}

void StrongEnemyShip::attack() {
	int* newPosition;
	int newVelocity[2] = {0, 1};
	
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
	
	delete newPosition;
	EnemyShip::attack();
}

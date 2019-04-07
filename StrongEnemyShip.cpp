#include "StrongEnemyShip.h"

StrongEnemyShip::StrongEnemyShip(MediumEnemyShip* l, MediumEnemyShip* r, const int yPos, BulletPool* bulletPool) : EnemyShip(bulletPool){
	left = l;
	right = r;
	yPosition = yPos;
	points = 200;
	setColor(13);
}

void StrongEnemyShip::attack() {
	int* newPosition;
	
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

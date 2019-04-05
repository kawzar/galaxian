#include "MediumEnemyShip.h"

MediumEnemyShip::MediumEnemyShip():EnemyShip(){
	setColor(5);
}

void MediumEnemyShip::setVelocity(const int vel[2]) {
	Ship::setVelocity(vel);
}

void MediumEnemyShip::setPosition(const int pos[2]) {
	Ship::setPosition(pos);
}

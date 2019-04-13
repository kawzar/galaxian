#include "MediumEnemyShip.h"

MediumEnemyShip::MediumEnemyShip(BulletPool* bulletPool, const int windowSizeX, const int windowSizeY):EnemyShip(bulletPool, windowSizeX, windowSizeY){
	setColor(14);
	points = 150;
}

void MediumEnemyShip::setVelocity(const int vel[2]) {
	Ship::setVelocity(vel);
}

void MediumEnemyShip::setPosition(const int pos[2]) {
	Ship::setPosition(pos);
}

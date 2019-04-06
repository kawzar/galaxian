#include "MediumEnemyShip.h"

#ifndef STRONGENEMYSHIP_H
#define STRONGENEMYSHIP_H

class StrongEnemyShip : public EnemyShip {
public:
	StrongEnemyShip(MediumEnemyShip* left, MediumEnemyShip* right, const int yPosition, BulletPool* bulletPool);
	void attack();
private:
	MediumEnemyShip* left;
	MediumEnemyShip* right;
};
#endif

#include "EnemyShip.h"

#ifndef MEDIUMENEMYSHIP_H 
#define ENEMYSHIP_H
class MediumEnemyShip : public EnemyShip {
public:
	MediumEnemyShip();
	void setVelocity(const int vel[2]);
	void setPosition(const int pos[2]);
};
#endif

#include "EnemyShip.h"

#ifndef MEDIUMENEMYSHIP_H 
#define ENEMYSHIP_H
class MediumEnemyShip : public EnemyShip {
public:
	void setVelocity(const int vel[2]);
};
#endif

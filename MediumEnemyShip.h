#include "EnemyShip.h"

#ifndef MEDIUMENEMYSHIP_H 
#define ENEMYSHIP_H
class MediumEnemyShip : public EnemyShip {
public:
	MediumEnemyShip(BulletPool* bulletPool, const int windowSizeX, const int windowSizeY);
	void setVelocity(const int vel[2]);
	void setPosition(const int pos[2]);
};
#endif

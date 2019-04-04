#include "Ship.h"

#ifndef ENEMYSHIP_H
#define ENEMYSHIP_H

enum EnemyShipState{
	FORMATION_MOVING_LEFT, 
	FORMATION_MOVING_RIGHT,
	ATTACKING_ALONE,
	ATTACKING_GROUP
};

class EnemyShip : public Ship {
public:
	EnemyShip();
	void handleStateAndUpdate(EnemyShipState s);
protected:
	EnemyShipState state;
	void updateMovingState(EnemyShipState state);
	bool isAlive, isLeftMost, isRightMost;
};
#endif
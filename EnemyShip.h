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
	virtual ~EnemyShip();
	void handleStateAndUpdate(EnemyShipState s);
	bool isInFormation();
	virtual void attack();
	void setAlive(const bool alive);
protected:
	EnemyShipState state;
	bool isInFormation_;
	
	int yPosition;
};
#endif

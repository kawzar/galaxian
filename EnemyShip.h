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
	void setFormationPosition(const int position[2]);
	void changeFormationPosition(const int velocity[2]);
protected:
	EnemyShipState state;
	bool isInFormation_;
	int yPosition;
	int formationPosition[2];
	
	void goBackToFormation();
};
#endif

#include "Ship.h"
#include "BulletPool.h"

#ifndef ENEMYSHIP_H
#define ENEMYSHIP_H

enum EnemyShipState{
	FORMATION_MOVING_LEFT, 
	FORMATION_MOVING_RIGHT,
	ATTACKING_ALONE
};

class EnemyShip : public Ship {
public:
	EnemyShip(BulletPool* bulletPool);
	virtual ~EnemyShip();
	void handleStateAndUpdate(EnemyShipState s);
	bool isInFormation();
	virtual void attack();
	void setAlive(const bool alive);
	void setFormationPosition(const int position[2]);
	void changeFormationPosition(const int velocity[2]);
	void shoot();
	void die();
	int getPoints();
protected:
	EnemyShipState state;
	bool isInFormation_;
	int yPosition;
	int formationPosition[2];
	int ticks, lastRefresh;
	const int bulletVelocity[2] = {0,2};
	BulletPool* bulletPool;
	int points;
	
	void goBackToFormation();
};
#endif

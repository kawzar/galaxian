#include "MediumEnemyShip.h"

#ifndef STRONGENEMYSHIP_H
#define STRONGENEMYSHIP_H

class StrongEnemyShip : public EnemyShip {
public:
private:
	MediumEnemyShip* left;
	MediumEnemyShip* right;
};

#include "StrongEnemyShip.h"

#ifndef FORMATION_H
#define FORMATION_H
enum FormationStates{
	FORMATION_RIGHT,
	FORMATION_LEFT
};

class Formation {
public:
	Formation();
	void handleStateAndUpdate();
	void makeSomeShipsAttack();
protected:
	static const int xSize = 5;
	static const int ySize = 4;
	FormationStates state;
	EnemyShip* formation [ySize][xSize];
	int leftLimit, rightLimit;
	
	void handleFormationStates(FormationStates s);
};
#endif

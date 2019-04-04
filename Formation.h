#include "EnemyShip.h"

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
protected:
	static const int xSize = 2;
	static const int ySize = 5;
	FormationStates state;
	EnemyShip* formation [xSize][ySize];
	
	void handleFormationStates(FormationStates s);
};
#endif

#include "EnemyShip.h"
#include <cstring>
using namespace std;

EnemyShip::EnemyShip(){
	char toDraw[3][8];
	strcpy(toDraw[0], "\\|\\/|/");
	strcpy(toDraw[1], " (  )");
	strcpy(toDraw[2], "  \\/");
	
	setSprite(toDraw);
	setColor(10);
}

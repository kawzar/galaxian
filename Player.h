#include "Ship.h"
#ifndef PLAYER_H
#define PLAYER_H
class Player : public Ship {
public:
	Player();
	void moveLeft();
	void moveRight();
};
#endif

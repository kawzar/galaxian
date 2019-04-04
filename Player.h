#include "Ship.h"
#ifndef PLAYER_H
#define PLAYER_H
enum PlayerStates {
	MOVE_RIGHT,
	MOVE_LEFT,
	SHOOT
};

class Player : public Ship {
public:
	Player();
	void changeState(PlayerStates state);
	virtual void move();
	
protected:
	PlayerStates playerState;
	void moveLeft();
	void moveRight();
};
#endif

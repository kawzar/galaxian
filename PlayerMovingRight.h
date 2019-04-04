#include "PlayerMovingLeft.h"

#ifndef PLAYERMOVINGRIGHT_H
#define PLAYERMOVINGRIGHT_H
class PlayerMovingRight : public ShipState {
public:
	PlayerMovingRight(){}
	
	virtual ShipState* handleState(Ship& ship, State state);
	virtual void update(Ship& ship);
	~PlayerMovingRight() {}
};
#endif

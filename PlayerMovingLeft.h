#include "ShipState.h"

#ifndef PLAYERMOVINGLEFT_H
#define PLAYERMOVINGLEFT_H

class PlayerMovingLeft : public ShipState {
public:
	PlayerMovingLeft()	{}
	
	virtual ShipState* handleState(Ship& ship, State state);	
	virtual void update(Ship& ship);
	~PlayerMovingLeft(){}
};
#endif

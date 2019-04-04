#ifndef SHIPSTATE_H
#define SHIPSTATE_H

#include "Ship.h"
#include "State.h"
#include <stdio.h>

class ShipState
{
public:
	virtual ~ShipState(){}
	virtual ShipState* handleState(Ship& ship, State state);
	virtual void update(Ship& ship);
};
#endif

#include "PlayerMovingLeft.h"
#include "PlayerMovingRight.h"

ShipState* PlayerMovingLeft::handleState(Ship& ship, State state) {
	if (state == INPUT_RIGHT) {					
		return new PlayerMovingRight();
	}
	
	return NULL;
}
	
void PlayerMovingLeft::update(Ship& ship) {
	//	chargeTime_++;
	//	if (chargeTime_ > MAX_CHARGE)
	//	{
	//		heroine.superBomb();
	//	}
}

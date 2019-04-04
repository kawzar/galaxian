#include "PlayerMovingRight.h"

ShipState* PlayerMovingRight::handleState(Ship& ship, State state) {
	if (state == INPUT_LEFT) {					
		return new PlayerMovingLeft();
	}
	
	return NULL;
}

void PlayerMovingRight::update(Ship& ship) {
//			chargeTime_++;
//			if (chargeTime_ > MAX_CHARGE)
//			{
//				heroine.superBomb();
//			}
}


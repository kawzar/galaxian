#include "Player.h"
Player::Player() : Ship() {
}

void Player::moveLeft() {
	velocity[0] = -1;
	velocity[1] = 0;
	Ship::move();
}

void Player::moveRight() {
	velocity[0] = 1;
	velocity[1] = 0;
	Ship::move();
}

void Player::changeState(PlayerStates state){
	if (playerState != state) {
		playerState = state;
	}
}

void Player::move(){
	if (playerState == MOVE_RIGHT){
		moveRight();
	} else if (playerState == MOVE_LEFT){
		moveLeft();
	}		
}

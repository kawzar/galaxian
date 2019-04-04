#include "Player.h"

Player::Player() : Ship() {
}

void Player::moveLeft() {
	velocity[0] = -1;
	velocity[1] = 0;
	move();
}

void Player::moveRight() {
	velocity[0] = 1;
	velocity[1] = 0;
	move();
}

//
//Sh Player::handleState(State state)
//{
//	//state_->handleState(*this, state);
//}

void Player::update()
{
	//state_->update(*this);
}

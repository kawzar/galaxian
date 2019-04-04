#include "Player.h"
#include <cstring>
using namespace std;

Player::Player() : Ship() {
	char toDraw [3][8];
	strcpy(toDraw[0], "  /\\");
	strcpy(toDraw[1], " (  )");
	strcpy(toDraw[2], "/|/\\|\\");	
	setSprite(toDraw);
	
	setColor(4);
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

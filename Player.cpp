#include "Player.h"
#include <cstring>
using namespace std;

Player::Player() : Ship() {
	char toDraw [3][8];
	strcpy(toDraw[0], "  /\\");
	strcpy(toDraw[1], " (  )");
	strcpy(toDraw[2], "/|/\\|\\");	
	setSprite(toDraw);
	bullet = new Bullet();
	
	setColor(10);
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

void Player::shoot() {
	if (!bullet->isActive()) {
		int velocity [2] = {0, -2};
		int* position = getPosition();
		int newPosition[2] = {0,0};
		newPosition[0] = position[0] + 2;
		newPosition[1] = position[1] - 2;
		
		bullet->init(newPosition, velocity, sprite->getColor());
		delete position;
	}
}

Bullet* Player::getBullet() { 
	return bullet;
}

void Player::updateBulletPosition() { 
	bullet->move();
}

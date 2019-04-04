#include <stdio.h>
#include <conio2.h>
#include <constream>
#include <windows.h>
#include <cstring>
#include "Ship.h"

using namespace std;
using namespace conio;

Ship::Ship() {
	this->sprite = new Sprite();
}
Ship::~Ship() {
	delete sprite;
};

void Ship::move() {
	int newPosition [2];
	int* currentPosition = sprite->getPosition();
	newPosition[0] = currentPosition[0] + velocity[0];
	newPosition[1] = currentPosition[1] + velocity[1];
	this->setPosition(newPosition);
	delete currentPosition;
};

void Ship::setPosition(const int newPosition[2]){
	sprite->setPosition(newPosition);
}

int* Ship::getPosition() {
	return this->sprite->getPosition();
}

void Ship::setColor(const int color) {
	sprite->setColor(color);
}

void Ship::draw() {
	sprite->draw();
}

void Ship::setVelocity(const int vel[2]) {
	velocity[0] = vel[0];
	velocity[1] = vel[1];
}

void Ship::setSprite(const char toDraw[4][8]) {
	sprite->setSprite(toDraw);
}

int* Ship::getVelocity() {
	return velocity;
}

#include <stdio.h>
#include <conio2.h>
#include <constream>
#include <windows.h>
#include "Sprite.h"

using namespace std;
using namespace conio;

Sprite::Sprite() {
	
}

Sprite::~Sprite() {
}

void Sprite::draw() {
	textcolor(color);
	
	for(int i = 0; i < sizeY; i++) {
		gotoxy(position[x], position[y] + i);
		puts(sprite[i]);
	}
}

void Sprite::setColor(const int color) {
	this->color = color;
}

void Sprite::setSprite(const char toDraw[4][8]) {
	for(int i = 0; i < sizeY; i++) {
		strcpy(sprite[i], toDraw[i]);
	}
}

void Sprite::setPosition(const int newPosition[2]) {
	position[x] = newPosition[x];
	position[y] = newPosition[y];
}

int* Sprite::getPosition() {
	return this -> position;
}

int Sprite::getColor() {
	return color;
}

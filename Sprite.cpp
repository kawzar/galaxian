#include <stdio.h>
#include <conio2.h>
#include <constream>
#include <windows.h>
#include "Sprite.h"

using namespace std;
using namespace conio;

Sprite::Sprite() {
	
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

void Sprite::setPosition(const int x, const int y) {
	position[0] = x;
	position[1] = y;
}

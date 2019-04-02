#include <stdio.h>
#include <iostream>
#include <cstring>
#include "Sprite.h"

using namespace std;

int main (int argc, char *argv[]) {
	char toDraw[4][8];
	strcpy(toDraw[0], "   /\\");
	strcpy(toDraw[1], "  (  )");
	strcpy(toDraw[2], " /|/\\|\\");
		
	Sprite* sprite = new Sprite();
	sprite->setColor(14);
	sprite->setPosition(10,10);
	sprite->setSprite(toDraw);
	sprite->draw();
	
	sprite->setColor(11);
	sprite->setPosition(25,10);
	sprite->setSprite(toDraw);
	sprite->draw();
	
	cout << endl;
	return 0;
}


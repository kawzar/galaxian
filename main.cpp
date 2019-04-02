#include <stdio.h>
#include <iostream>
#include <cstring>
#include "Sprite.h"

using namespace std;

int main (int argc, char *argv[]) {
	char toDraw[3][8];
	strcpy(toDraw[0], "   /\\");
	strcpy(toDraw[1], "  (  )");
	strcpy(toDraw[2], " /|/\\|\\");
	
	Sprite* board [5];

	for (int i = 0; i < 1; i++) {
		board[i] = new Sprite();
		
		board[i]->setColor(14);
		board[i]->setPosition(i + 9, 1);
		board[i]->setSprite(toDraw);
		board[i]->draw();
	}
	
	
	cout << endl;
	return 0;
}


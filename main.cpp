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
	int newPosition[2] = {1,1};
	
	for (int i = 0; i < 5; i++) {
		board[i] = new Sprite();
		newPosition[0] = newPosition[0] + board[i]->spacingX;

		board[i]->setColor(14);
		board[i]->setPosition(newPosition);
		board[i]->setSprite(toDraw);
		board[i]->draw();
	}
	
	
	cout << endl;
	return 0;
}


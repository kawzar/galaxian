#include <stdio.h>
#include <iostream>
#include <cstring>
#include <time.h>
#include <windows.h>
#include <constream>
#include <conio.h>

#include "Ship.h"

using namespace std;
using namespace conio;

int main (int argc, char *argv[]) {
	char toDraw[3][8];
	strcpy(toDraw[0], "   /\\");
	strcpy(toDraw[1], "  (  )");
	strcpy(toDraw[2], " /|/\\|\\");
	
	Sprite* board [5];
	int newPosition[2] = {1,1};
	
	int ticks, lastRefresh;
	ticks = 10;
	lastRefresh = clock();
	
	for (int i = 0; i < 5; i++) {
		board[i] = new Sprite();
		newPosition[0] = newPosition[0] + board[i]->spacingX;

		board[i]->setColor(14);
		board[i]->setPosition(newPosition);
		board[i]->setSprite(toDraw);
		board[i]->draw();
	}
	
	Ship* ships[3];
	newPosition[0] = 1;
	newPosition[1] = 10;
	
	for (int i = 0; i < 3; i++) {
		ships[i] = new Ship();
		newPosition[0] = newPosition[0] + 9;
		int velocity[2] = {1, 0};
		
		ships[i]->setColor(7);
		ships[i]->setPosition(newPosition);
		ships[i]->setSprite(toDraw);
		ships[i]->setVelocity(velocity);
		ships[i]->draw();
	}
	
	while(true){
		if(clock() > lastRefresh + ticks) { 
			clrscr();
			for (int i = 0; i < 3; i++) {
				ships[i]->move();
				ships[i]->draw();
			}
			
			lastRefresh = clock();
			
		}
	}
	cout << endl;
	return 0;
}


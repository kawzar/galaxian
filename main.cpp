#include <stdio.h>
#include <iostream>
#include <cstring>
#include <time.h>
#include <constream>
#include <conio.h>
#include <windows.h>

#include "GameManager.h"

using namespace std;
using namespace conio;


int main (int argc, char *argv[]) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	_CONSOLE_SCREEN_BUFFER_INFO info;	
	GetConsoleScreenBufferInfo(hConsole,&info);
	//SMALL_RECT windowSize = {0, 0, 119, 59};
	int windowSizeX = info.dwMaximumWindowSize.X-3;
	int windowSizeY = info.dwMaximumWindowSize.Y-3;
	SMALL_RECT windowMaxSize = {0, 0, windowSizeX, windowSizeY};
	
	SetConsoleWindowInfo(hConsole, TRUE, &windowMaxSize);
	
	GameManager * gameManager = new GameManager(windowSizeX, windowSizeY);
	gameManager->introScreen();
	gameManager->gameLoop();
	
	cout << endl;
	return 0;
}


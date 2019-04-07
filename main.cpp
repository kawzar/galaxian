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
	SMALL_RECT windowSize = {0, 0, 119, 59};
	//SMALL_RECT windowMaxSize = {0, 0, info.dwMaximumWindowSize.X-1, info.dwMaximumWindowSize.Y-1};
	
	SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
	
	GameManager * gameManager = new GameManager();
	gameManager->introScreen();
	gameManager->gameLoop();
	
	cout << endl;
	return 0;
}


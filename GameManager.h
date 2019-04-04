#include "Player.h"
#include "Formation.h"
#ifndef GAMEMANAGER_H	
#define	GAMEMANAGER_H	

class GameManager {
public:
	GameManager();
	~GameManager();
	
	void gameLoop();
	
private:
	Formation* formation;
	Player* player;
	const int yMax = 119;
	const int xMax = 59;
	const int xMin = 1;
	const int yMin = 1;
	
	void setupPlayer();
};
#endif

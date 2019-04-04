#include "Player.h"
#ifndef GAMEMANAGER_H	
#define	GAMEMANAGER_H	

class GameManager {
public:
	GameManager();
	~GameManager();
	
	void gameLoop();
	
private:
	Ship* formation [2][5];
	Player* player;
	const int yMax = 119;
	const int xMax = 59;
	const int xMin = 1;
	const int yMin = 1;
	
	void moveFormation();
	void setupFormation();
	void setupPlayer();
};
#endif

#include "Player.h"
#include "Formation.h"

#ifndef GAMEMANAGER_H	
#define	GAMEMANAGER_H	

class GameManager {
public:
	GameManager(const int windowSizeX, const int windowSizeY);
	~GameManager();
	
	void gameLoop();
	void introScreen();
	
private:
	Formation* formation;
	Player* player;
	const int yMax = 119;
	const int xMax = 59;
	const int xMin = 1;
	const int yMin = 1;
	BulletPool* bulletPool;
	bool gameLoop_;
	int score;
	int windowX, windowY;
	
	void setupPlayer();
	void printScoreAndLife();
	void printHighscores();
};
#endif

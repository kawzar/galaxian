#include "Player.h"
#include "Formation.h"
#include "ScoreManager.h"

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
	int windowX, windowY;
	ScoreManager* scoreManager;
	
	void setupPlayer();
	void printScoreAndLife();
	void printHighscores();
	void saveScore(const char* name, const int score);
};
#endif

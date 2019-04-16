#ifndef SCOREMANAGER_H 
#define SCOREMANAGER_H
class Score{
public:
	Score() {};
	char name[10];
	int score;
};

class ScoreManager {
public:
	ScoreManager();
	~ScoreManager();
	void getHighScores(Score* highScores[5]);
	void saveHighScores(Score* scores[5]);
	void addScore(Score* scores[5], Score* newScore, Score* result[5]);
	void getDummyScore(Score* highScores[5]);
	void swap(Score *xp, Score *yp) ;
};

#endif

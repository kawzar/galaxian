#include "ScoreManager.h"
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

ScoreManager::ScoreManager(){
}

void ScoreManager::getHighScores(Score* highScores[5]){
	ifstream input_file("scores.data", ios::binary);
	Score* master[5];
    
	if (!input_file)
	{
		getDummyScore(highScores);
		return;
	}
	
	long checkBytes;
	input_file.seekg(0, ios::end); // put pointer at end of file
	checkBytes = input_file.tellg(); // get file size in bytes, store it in variable "checkBytes";
	
	if (checkBytes > 0) // if file size is bigger than 0 bytes
	{		
		input_file.seekg(0, ios::beg); // put pointer back at beginning
		input_file.read((char*)&master, sizeof(master)); 
		
		for (int i = 0; i <5; i++) {
			strcpy(highScores[i]->name, master[i]->name);
			highScores[i]->score = master[i]->score;
		}
				
		input_file.close();
	}
}

void ScoreManager::saveHighScores(Score* scores[5]){
	ofstream output_file("scores.data", ios::binary);
	
	for (int i =0; i < 5; i++) { 
		output_file.write((char*)scores[i], sizeof(scores));
	}
	
	output_file.close();
}

void ScoreManager::addScore(Score* scores[5], Score* newScore, Score* result[5]) {
	for (int i = 0; i < 5; i++) {
		if (scores[i]->score <= newScore->score) {
			
			strcpy(result[i]->name, newScore->name);
			result[i]->score = newScore->score;
			
			for (int j = i + 1; j < 5; j++) {
				result[j] = new Score();
				strcpy(result[j]->name, scores[j -1]->name);
				result[j]->score = scores[j -1]->score;
			}
			
			break;
			
		} else {
			result[i] = new Score();
			strcpy(result[i]->name, scores[i]->name);
			result[i]->score = scores[i]->score;
		}
	};
	
	saveHighScores(result);
}

void ScoreManager::getDummyScore(Score* highScores[5]) { 
	Score* master = new Score();
	strcpy(master->name, "XXXXX");
	master->score = 0;
	
	for (int i = 0; i < 5; i++) {
		highScores[i] = new Score();
		strcpy(highScores[i]->name, master->name);
		highScores[i]->score = master->score;
	}
}

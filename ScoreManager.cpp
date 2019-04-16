#include "ScoreManager.h"
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;

ScoreManager::ScoreManager(){
}

void ScoreManager::getHighScores(Score* highScores[5]){
	ifstream input_file("scores.data", ios::binary);
	
	if (!input_file)
	{
		getDummyScore(highScores);
		return;
	}
	
	long checkBytes;
	input_file.seekg(0, ios::end); // put pointer at end of file
	checkBytes = input_file.tellg(); // get file size in bytes, store it in variable "checkBytes";
	getDummyScore(highScores);
	
	if (checkBytes > 0) // if file size is bigger than 0 bytes
	{		
		input_file.seekg(0, ios::beg); // put pointer back at beginning
		
		Score temp;
		
		for (int i = 0; i <5 && !input_file.eof(); i++) {			
			input_file.read((char*)&temp, sizeof(Score)); 
			highScores[i] = new Score();
			strcpy(highScores[i]->name, temp.name);
			highScores[i]->score = temp.score;
		}
		
		input_file.close();
	}
}

void ScoreManager::saveHighScores(Score* scores[5]){
	ofstream output_file("scores.data", ios::binary);
	
	for (int i = 0; i < 5; i++) { 
		output_file.write((char*)scores[i], sizeof(Score));
	}
	
	output_file.close();
}

void ScoreManager::addScore(Score* scores[5], Score* newScore, Score* result[5]) {
	Score* aux [6];
	for (int i = 0; i < 5; i++) {
		aux[i] = new Score();
		aux[i]->score = scores[i]->score;
		strcpy(aux[i]->name, scores[i]->name);
	}
	
	aux[5] = new Score();
	aux[5]->score = newScore->score;
	strcpy(aux[5]->name, newScore->name);
	
	int i, j; 
	for (i = 0; i < 5; i++){     
		for (j = 0; j < 5-i; j++) {
			if (aux[j]->score < aux[j+1]->score) {
				swap(aux[j], aux[j+1]); 
			}
		}
	}
	
	for (int i = 0; i < 5; i++) {
		result[i] = new Score();
		result[i]->score = aux[i]->score;
		strcpy(result[i]->name, aux[i]->name);
	}
	
	saveHighScores(result);
}

void ScoreManager::swap(Score *xp, Score *yp) 
{ 
	Score* temp = new Score();
	temp->score = xp->score;
	strcpy(temp->name, xp->name);
	
	xp->score = yp->score; 
	strcpy(xp->name, yp->name);
	
	yp->score = temp->score;
	strcpy(yp->name, temp->name);
}

void ScoreManager::getDummyScore(Score* highScores[5]) { 
	for (int i = 0; i < 5; i++) {
		highScores[i] = new Score();
		strcpy(highScores[i]->name, "XXXXXX");
		highScores[i]->score = 0;
	}
}

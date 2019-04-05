#include "Formation.h"

Formation::Formation(){
	// initialize ships
	state = FormationStates::FORMATION_RIGHT;
	int newPosition[2] = {1,1};
	leftLimit = 5;
	
	for (int i = 0; i < ySize; i++) {		
		for (int j = 0; j < xSize; j++) {
			if (i == 1) {
				formation[i][j] = new MediumEnemyShip();
			} else {
				formation[i][j] = new EnemyShip();
			}
			
			int velocity[2] = {1, 0};
			newPosition[0] = newPosition[0] + 9;
			rightLimit = newPosition[0] + 9;
			
			formation[i][j]->setPosition(newPosition);
			formation[i][j]->setVelocity(velocity);
		}
		newPosition[0] = 1;
		newPosition[1] = newPosition[1] + 4;
	}
	
	// set left strong ship
	delete formation[0][1];
	formation[0][1] = new StrongEnemyShip((MediumEnemyShip*)formation[0][0], (MediumEnemyShip*)formation[0][2], 7);

	int velocity[2] = {1, 0};
	newPosition[0] = 19;
	newPosition[1] = 1;
	formation[0][1]->setPosition(newPosition);
	formation[0][1]->setVelocity(velocity);
	
	// set right strong ship
	delete formation[0][3];
	formation[0][3] = new StrongEnemyShip((MediumEnemyShip*)formation[0][2], (MediumEnemyShip*)formation[0][4], 7);

	newPosition[0] = 19 + 9 + 9;
	newPosition[1] = 1;
	formation[0][3]->setPosition(newPosition);
	formation[0][3]->setVelocity(velocity);
	
	formation[0][0]->setAlive(false);
	formation[0][2]->setAlive(false);
	formation[0][4]->setAlive(false);
}

void Formation::handleStateAndUpdate(){	
	switch (state){
	case FORMATION_LEFT:
		leftLimit--;
		rightLimit--;
		if (leftLimit <= 1) {
			handleFormationStates(FormationStates::FORMATION_RIGHT);
		} else {
			handleFormationStates(state);
		}
		break;
	case FORMATION_RIGHT:
		leftLimit++;
		rightLimit++;
		if (rightLimit >= 119) {
			handleFormationStates(FormationStates::FORMATION_LEFT);
		} else {
			handleFormationStates(state);
		}
		break;
	default:
		handleFormationStates(state);
		break;
	}
}

void Formation::handleFormationStates(FormationStates s){
	for (int i = 0; i < ySize; i++) {
		for (int j = 0; j< xSize; j++) {
			if (s == FORMATION_LEFT){
				formation[i][j]->handleStateAndUpdate(EnemyShipState::FORMATION_MOVING_LEFT);
				state = FORMATION_LEFT;
			}
			else if (s == FORMATION_RIGHT){ 
				formation[i][j]->handleStateAndUpdate(EnemyShipState::FORMATION_MOVING_RIGHT);
				state = FORMATION_RIGHT;
			}
			
			
			formation[i][j]->move();
			formation[i][j]->draw();
		}		
	}
}

#include "Ship.h"
#include "Bullet.h"

#ifndef PLAYER_H
#define PLAYER_H
enum PlayerStates {
	MOVE_RIGHT,
	MOVE_LEFT,
	SHOOT
};

class Player : public Ship {
public:
	Player();
	void changeState(PlayerStates state);
	void shoot();
	virtual void move();
	Bullet* getBullet();
	void updateBulletPosition();
	int getLife();
	void damage();
	void die();
	
protected:
	int life = 5;
	PlayerStates playerState;
	Bullet* bullet;
	void moveLeft();
	void moveRight();
};
#endif

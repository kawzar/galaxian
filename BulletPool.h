#include "Bullet.h"
#include "Player.h"

#ifndef BULLETPOOL_H
#define BULLETPOOL_H

class BulletPool{
public:
	BulletPool();
	~BulletPool();
	void create(const int position[2], const int velocity[2], const int color);
	void update();
	void checkCollisions(Player* player);
	
protected:
	static const int size = 10;
	Bullet* pool [size];
};
#endif

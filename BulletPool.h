#include "Bullet.h"

#ifndef BULLETPOOL_H
#define BULLETPOOL_H

class BulletPool{
public:
	BulletPool();
	~BulletPool();
	void create(const int position[2], const int velocity[2], const int color);
	void update();
	
protected:
	static const int size = 20;
	Bullet* pool [size];
};
#endif

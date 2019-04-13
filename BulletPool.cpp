#include "BulletPool.h"

BulletPool::BulletPool(const int windowSizeX, const int windowSizeY){
	for (int i = 0; i< size; i++) {
		pool[i] = new Bullet(windowSizeX, windowSizeY);
	}
}

BulletPool::~BulletPool() { 
	for (int i = 0; i < size; i++) { 
		delete pool[i];
	}
}
void BulletPool::create(const int position[2], const int velocity[2], const int color) {
	for(int i = 0; i < size; i++) {
		if (!pool[i]->isActive()) {
			pool[i]->init(position, velocity, color);
			break;
		}
	}
}

void BulletPool::update() {
	for(int i = 0; i < size; i++) {
		if (pool[i]->isActive()) {
			pool[i]->move();
		}
	}
}

void BulletPool::checkCollisions(Player* player) {
	for (int i = 0; i < size; i++) {
		if (pool[i]->isActive()) {
			if (player->intersects(pool[i]->getPosition())) {
				pool[i]->die();
				player->damage();
			}
		}
	}
	
}

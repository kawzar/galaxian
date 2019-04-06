#include "BulletPool.h"

BulletPool::BulletPool(){
	for (int i = 0; i< size; i++) {
		pool[i] = new Bullet();
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

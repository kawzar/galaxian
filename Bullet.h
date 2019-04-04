#ifndef BULLET_H
#define BULLET_H

class Bullet{
public:
	bool isActive();
	Bullet create(const int position[2], const int velocity[2]);
	void move();
	
};

#endif

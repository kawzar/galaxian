#ifndef BULLET_H
#define BULLET_H

class Bullet{
public:
	Bullet();
	bool isActive();
	void init(const int position[2], const int velocity[2], const int color);
	void move();
	void die();
	int* getPosition();
	
protected:
	bool inUse_;
	int position_[2];
	int velocity_[2];
	const char* sprite = "*";
	int color_;
	
	void draw();
};
#endif

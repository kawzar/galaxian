#include "Sprite.h"
#ifndef SHIP_H	
#define	SHIP_H	

class Ship {
public:
	Ship();
	~Ship();
	virtual void move();
	void setVelocity(const int vel[2]);
	int* getPosition();
	int* getVelocity();
	void setPosition(const int position[2]);
	void shoot(const int xVel, const int yVel);
	void draw();
	bool isAlive();
	bool intersects(const int otherPosition[2]);
protected:
	Sprite* sprite;
	int velocity[2];	
	int xSize = 3;
	int ySize = 8;
	
	void setSprite(const char toDraw[4][8]);
	void setColor(const int color);
	bool isAlive_;
};
#endif

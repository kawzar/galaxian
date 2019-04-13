#include "Sprite.h"
#ifndef SHIP_H	
#define	SHIP_H	

class Ship {
public:
	Ship(const int windowSizeX, const int windowSizeY);
	~Ship();
	virtual void move();
	void setVelocity(const int vel[2]);
	int* getPosition();
	int* getVelocity();
	void setPosition(const int position[2]);
	void shoot();
	void draw();
	bool isAlive();
	bool intersects(const int otherPosition[2]);
	virtual void die() = 0;
protected:
	Sprite* sprite;
	int velocity[2];	
	int xSize = 3;
	int ySize = 8;
	
	void setSprite(const char toDraw[4][8]);
	void setColor(const int color);
	bool isAlive_;
	int windowX, windowY;
};
#endif

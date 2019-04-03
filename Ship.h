#include "Sprite.h"

class Ship {
public:
	Ship();
	~Ship();
	void move();
	void setVelocity(const int vel[2]);
	int* getPosition();
	int* getVelocity();
	void setPosition(const int position[2]);
	void shoot(const int xVel, const int yVel);
	void draw();
	void setSprite(const char toDraw[4][8]);
	void setColor(const int color);
protected:
	Sprite* sprite;
	int velocity[2];	
};

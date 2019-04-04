#include "Sprite.h"
#include "State.h"

#ifndef SHIP_H	
#define	SHIP_H	
class ShipState;

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
	void setState(ShipState* state);
	virtual void handleState(State state);
	virtual void update();	
	
protected:
	Sprite* sprite;
	int velocity[2];	
	ShipState* state_;
};
#endif

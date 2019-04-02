class Ship {
public:
	Ship();
	~Ship();
	void move(const int x, const int y, const int xVel, const int yVel);
	void shoot(const int xVel, const int yVel);
};

#ifndef	SPRITE_H	
#define	SPRITE_H	
class Sprite{
public:
	const int spacingX = 9;
	const int spacingY = 3;
	Sprite();
	~Sprite();
	void setSprite(const char toDraw[4][8]);
	void setColor(const int color);
	void setPosition(const int newPosition[2]);
	int* getPosition();
	int getColor();
	void draw();
private:
	const char EMPTY = ' ';
	const int sizeX = 7;
	const int sizeY = 3;
	const int x = 0;
	const int y = 1;
	char sprite [4][8];
	int position[2];
	int color;
};
#endif

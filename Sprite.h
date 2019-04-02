class Sprite{
public:
	Sprite();
	~Sprite();
	void setSprite(const char toDraw[4][8]);
	void setColor(const int color);
	void setPosition(const int x, const int y);
	void draw();
private:
	const char EMPTY = ' ';
	const int sizeX = 7;
	const int sizeY = 3;
	const int x = 0;
	const int y = 1;
	char sprite [3][7];
	int position[2];
	int color;
};

#ifndef TABLE_H
#define TABLE_H 

class Board {
public:
	static const int EMPTY = 0;
	static const int PLAYER1_FLAG = 1;
	static const int PLAYER2_FLAG = 2;

	static const int DEFAULT_BOUNDARY_X = 3;
	static const int DEFAULT_BOUNDARY_Y = 3;

	Board();
	Board (int boundaryX, int boundaryY);
	virtual ~Board ();

	void clear();

	void putFlag(int x, int y, int flag);
	int getFlag(int x, int y) const;

	int getSizeX() const{
		return _sizeX;
	}

	int getSizeY() const{
		return _sizeY;
	}

private:
	int **_table;
	int _sizeX;
	int _sizeY;

	void init(int boundaryX, int boundaryY);

	void setSizeX(int sizeX){
		_sizeX = sizeX;
	}

	void setSizeY(int sizeY){
		_sizeY = sizeY;
	}
};

#endif

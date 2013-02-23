#ifndef FLOW_CONTROLLER
#define FLOW_CONTROLLER 

#include "Board.h"

class Controller {
public:
	static const int VALID_MOVE = 1;
	static const int INVALID_MOVE = -1;

	Controller ();
	virtual ~Controller ();

	int getCurrentPlayer() const;

	int putFlag(int x, int y);
	int getFlag(int x, int y) const;

	int getSizeX() const;
	int getSizeY() const;

	bool isGameEnd();

private:
	Board *_board;
	int _currentPlayer;
};

#endif

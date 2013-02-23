#include "Controller.h"

Controller::Controller(){
	_board = new Board(3, 3);
	_currentPlayer = Board::PLAYER1_FLAG;
}

Controller::~Controller(){
	delete _board;
}

int Controller::getCurrentPlayer() const{
	return _currentPlayer;
}

int Controller::putFlag(int x, int y){
	if(_board->getFlag(x, y) == Board::EMPTY){
		_board->putFlag(x, y, _currentPlayer);
		_currentPlayer = _currentPlayer % 2 + 1;
		return Controller::VALID_MOVE;
	}
	return Controller::INVALID_MOVE;
}

int Controller::getFlag(int x, int y) const{
	return _board->getFlag(x, y);
}

int Controller::getSizeX() const{
	return _board->getSizeX();
}

int Controller::getSizeY() const{
	return _board->getSizeY();
}

bool Controller::isGameEnd(){
	for (int y = 0; y < _board->getSizeY(); y++) {
		for (int x = 0; x < _board->getSizeX(); x++) {
			if(_board->getFlag(x, y) == Board::EMPTY){
				return false;
			}
		}
	}
	return true;
}

#include <iostream>
#include "Board.h"

Board::Board(){
	init(Board::DEFAULT_BOUNDARY_X, Board::DEFAULT_BOUNDARY_Y);
}

Board::Board(int boundaryX, int boundaryY){
	init(boundaryX, boundaryY);
}

Board::~Board(){
	//do nothing~
}

void Board::init(int boundaryX, int boundaryY){
	setSizeX(boundaryX);
	setSizeY(boundaryY);
	_table = new int*[boundaryY];

	for (int indexY = 0; indexY < getSizeY(); indexY++) {
		_table[indexY] = new int[getSizeY()];
	}

	clear();
}

void Board::clear(){
	for (int indexY = 0; indexY < getSizeY(); indexY++) {
		for (int indexX = 0; indexX < getSizeX(); indexX++) {
			_table[indexY][indexX] = 0;
		}
	}
}

void Board::putFlag(int x, int y, int flag){
	_table[y][x] = flag;
}

int Board::getFlag(int x, int y) const{
	return _table[y][x];
}

#include <iostream>
using namespace std;

#include <string.h>
#include <ncurses.h>
#include "View.h"
#include "Board.h"

View::View(Controller con){
	//ncurses
	initscr();
	cbreak();
	noecho();
	start_color();
	curs_set(0);
	ESCDELAY = 0;
	keypad(stdscr, TRUE);

	_controllerPtr = &con;
	setCursorX(0);
	setCursorY(0);
}

View::~View(){
	delete _controllerPtr;
}

void View::start(){
	while(true){
		draw();
		command();
	}
}

void View::command(){
	int command;

	command = getch();

	int modifyX = 0;
	int modifyY = 0;

	if(command == KEY_LEFT){
		modifyX = -1;
	}
	else if(command == KEY_RIGHT){
		modifyX = 1;
	}
	else if(command == KEY_UP){
		modifyY = -1;
	}
	else if(command == KEY_DOWN){
		modifyY = 1;
	}
	else if(command == 10){
		int result = _controllerPtr->putFlag(getCursorX(), getCursorY());
		if(result == Controller::INVALID_MOVE){
			mvprintw(1, 10, "Invalid movement!");
			refresh();
			getch();
		}
	}
	else if(command == 27){
		quit("bye bye");
	}

	int modifiedX = getCursorX() + modifyX;
	int modifiedY = getCursorY() + modifyY;

	if(modifiedX < _controllerPtr->getSizeX() && modifiedX  >= 0){
		setCursorX(modifiedX);
	}
	if(modifiedY < _controllerPtr->getSizeY() && modifiedY  >= 0){
		setCursorY(modifiedY);
	}
}

void View::draw(){
	clear();

	int lx;
	int ly;

	for (int y = 0; y < _controllerPtr->getSizeY(); y++) {
		for (int x = 0; x < _controllerPtr->getSizeX(); x++) {
			lx = x * 2;
			ly = y * 2;
			if(_controllerPtr->getFlag(x, y) == Board::PLAYER1_FLAG){
				mvprintw(ly, lx, "O");
			}
			else if(_controllerPtr->getFlag(x, y) == Board::PLAYER2_FLAG){
				mvprintw(ly, lx, "X");
			}

			//print seperate
			if(x < _controllerPtr->getSizeX() - 1){
				mvprintw(ly, lx + 1, "|");
			}
		}
		if(y < _controllerPtr->getSizeY() - 1){
			mvprintw(ly + 1, 0, "-+-+-");
		}
	}

	//draw cursor
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
	attron(COLOR_PAIR(1));
	mvprintw(getCursorY() * 2, getCursorX() * 2, "@");
	attroff(COLOR_PAIR(1));

	//draw current player message
	char *msg;
	if(_controllerPtr->getCurrentPlayer() == Board::PLAYER1_FLAG){
		msg = (char *)"It's player1's turn.";
	}
	else{
		msg = (char *)"It's player2's turn.";
	}
	mvprintw(0, 10, msg);

	//is the game end?
	if(_controllerPtr->isGameEnd()){
		quit("The game is end. Bye bye");
	}

	refresh();
}

void View::quit(const char* msg){
	clear();

	int x, y;
	getmaxyx(stdscr, y,x);

	mvprintw(y / 2, (x - strlen(msg)) / 2, msg);

	refresh();
	getch();

	endwin();
	exit(0);
}

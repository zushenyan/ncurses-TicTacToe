#ifndef VIEW_H
#define VIEW_H 

#include "Controller.h"

class View{
public:
	View (Controller con);
	virtual ~View ();

	void start();
	void command();
	void draw();

	int getCursorX() const{
		return _cursorX;
	}

	int getCursorY() const{
		return _cursorY;
	}

private:
	int _cursorX;
	int _cursorY;
	Controller *_controllerPtr;

	void setCursorX(int x){
		_cursorX = x;
	}

	void setCursorY(int y){
		_cursorY = y;
	}

	void quit(const char* msg);
};

#endif

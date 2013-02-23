#include <iostream>
using namespace std;

#include "Controller.h"
#include "Board.h"
#include "View.h"

int main(int argc, const char *argv[]) {
	Controller con;

	View v(con);

	v.start();

	return 0;
}

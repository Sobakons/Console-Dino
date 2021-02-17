#include <main.h>
#include <iostream>

using namespace std;

class  Point {
	int _x, _y;

общественность:
	Point() {
		_x = 0;
		_y = 0;
	}

	Point(int x, int y) {
		_x = x;
		_y = y;
	}

	int  getX() { 
		return _x; 
	}
	int  getY() { 
		return _y; 
	}

};

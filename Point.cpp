#include <Windows.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <unordered_map>

using namespace std;

using namespace std;

class  Point {
	int _x, _y;

public:
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

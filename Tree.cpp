#include <Windows.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <unordered_map>

using namespace std;

class Tree : public ParkObject {
private:
	COLORREF _color;

public:
	Tree(int cellX, int cellY, int cellSize, COLORREF color) : ParkObject(cellX, cellY, cellSize) {
		_color = color;
	}
	COLORREF color() {
		return _color;
	}
	void draw(ConsoleDrawer& cd) {
		//Переходим от ячеек к координатам пикселей
		int x = getX();
		int y = getY();

		int d = _cellSize / 10;
		cd.drawRect(Point(x + 4 * d, y + _cellSize), Point(x + 6 * d, y + _cellSize - 2 * d), ConsoleColor::brown(), true);
		cd.drawTriangle(Point(x + 2 * d, y + _cellSize - 2 * d), Point(x + _cellSize / 2, y + d), Point(x + _cellSize - 2 * d, y + _cellSize - 2 * d), _color, true);
	}
};

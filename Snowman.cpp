#include <Windows.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <unordered_map>

using namespace std;

class SnowMan : public ParkObject {

public:
	SnowMan(int cellX, int cellY, int cellSize) : ParkObject(cellX, cellY, cellSize) { }

	void draw(ConsoleDrawer& cd) {
		//Переходим от ячеек к координатам пикселей
		int x = getX();
		int y = getY();

		double d = _cellSize / 100.0;
		cd.drawCircle(Point(x + _cellSize / 2, y + _cellSize - 20 * d), 20 * d, ConsoleColor::white(), true);
		cd.drawCircle(Point(x + _cellSize / 2, y + _cellSize - 55 * d), 15 * d, ConsoleColor::white(), true);
		cd.drawCircle(Point(x + _cellSize / 2, y + _cellSize - 80 * d), 10 * d, ConsoleColor::white(), true);
		cd.drawRect(Point(x + _cellSize / 2 - 5 * d, y + 10 * d), Point(x + _cellSize / 2 + 5 * d, y + d), ConsoleColor::brown(), true);
	}
};

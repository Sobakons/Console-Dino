#include <Windows.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <unordered_map>

using namespace std;

class Pit : public ParkObject {
private:
public:
	Pit(int cellX, int cellY, int cellSize) : ParkObject(cellX, cellY, cellSize) {};
	void draw(ConsoleDrawer& cd) {
		//Переходим от ячеек к координатам пикселей
		int x = getX();
		int y = getY();

		cd.drawRect(Point(x + 16 + _cellSize / 2, y + _cellSize + 16 + _cellSize / 2), Point(x - 16 + _cellSize / 2, y + _cellSize - 16 + _cellSize / 2), ConsoleColor::black(), true);
	}
};

#include <Windows.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <unordered_map>

using namespace std;

class HappyDino : public ParkObject {
private:
	int _health;
	int _level;
public:
	HappyDino(int cellX, int cellY, int cellSize) : ParkObject(cellX, cellY, cellSize) {
		_health = 3;
		_level = 1;
	}
	int& level() {
		return _level;
	}
	int& health() {
		return _health;
	}
	void draw(ConsoleDrawer& cd) {

		//Переходим от ячеек к координатам пикселей
		int x = getX();
		int y = getY();
		COLORREF color = ConsoleColor::green();

		double d = _cellSize / 125.0;
		cd.drawRect(Point(x + d, y + 63 * d), Point(x + 24 * d, y + 53 * d), color, true);
		cd.drawRect(Point(x + 75 * d, y + 63 * d), Point(x + 98 * d, y + 53 * d), color, true);
		cd.drawRect(Point(x + 27 * d, y + 93 * d), Point(x + 72 * d, y + 35 * d), color, true);//body
		cd.drawRect(Point(x + 27 * d, y + 124 * d), Point(x + 42 * d, y + 94 * d), color, true);
		cd.drawRect(Point(x + 57 * d, y + 124 * d), Point(x + 72 * d, y + 94 * d), color, true);
		cd.drawRect(Point(x + 27 * d, y + 32 * d), Point(x + 88 * d, y + 2 * d), color, true);//head
		cd.drawCircle(Point(x + 42 * d, y + 12 * d), 8 * d, ConsoleColor::gray(), true);
		cd.drawTriangle(Point(x + 27 * d, y), Point(x + 49 * d, y - 45 * d), Point(x + 72 * d, y), ConsoleColor::red(), true);
		cd.drawCircle(Point(x + 49 * d, y - 50 * d), 10 * d, ConsoleColor::white(), true);

	}

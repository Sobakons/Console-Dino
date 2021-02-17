#include <Windows.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <unordered_map>

// Это самый базовый класс, от которого наследуются все объекты, которые появляются на поле
class ParkObject {
protected:
	int _cellX, _cellY, _cellSize;

public:
	ParkObject(int cellX, int cellY, int cellSize) {
		_cellX = cellX;
		_cellY = cellY;
		_cellSize = cellSize;
	}

	bool isInside(int cellX, int cellY) {
		return (_cellX == cellX) && (_cellY == cellY);
	}

	int getCellX() {
		return _cellX;
	}

	int getCellY() {
		return _cellY;
	}

	int getX() {
		return _cellX * _cellSize;
	}

	int getY() {
		return _cellY * _cellSize;
	}

};

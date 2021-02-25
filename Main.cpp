#include <Windows.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <unordered_map>

using namespace std;

int main() {

	ConsoleDrawer cd;
	srand(time(0));

	const int CellSize = 40;
	int width = cd.getWidth() / CellSize;
	int height = cd.getHeight() / CellSize;
	DinoPark dinoPark(width, height, CellSize, 5);

	dinoPark.addSnowMan(1, 1);
	dinoPark.addSnowMan(5, 6);
	dinoPark.addSnowMan(10, 4);

	dinoPark.addTree(1, 2, ConsoleColor::red());
	dinoPark.addTree(1, 3, ConsoleColor::green());
	dinoPark.addTree(1, 4, ConsoleColor::blue());
	dinoPark.addTree(5, 4, ConsoleColor::yellow());

	dinoPark.addPit(3, 9);
	dinoPark.addPit(11, 6);
	dinoPark.addPit(8, 2);
	dinoPark.addPit(15, 8);
	dinoPark.addPit(1, 5);

	dinoPark.addHappyDino(5, 3);

	cd.clearScreen();

	while (cd.isWork()) {
		cd.drawBackground();
		dinoPark.draw(cd);
		dinoPark.step(cd);
	}
	return 0;
}

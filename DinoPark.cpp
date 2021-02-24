#include <Windows.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <unordered_map>

using namespace std;

class DinoPark {
	int _cellsXCount;
	int _cellsYCount;
	int _cellSize;
	vector<SnowMan> _snowmen;
	vector<Tree> _trees;
	vector<Pit> _pits;
	vector<HappyDino> _hDino;
	vector<COLORREF> _colors;
	
	vector<COLORREF(*)()> fcolors = { ConsoleColor::green, ConsoleColor::red, ConsoleColor::blue, ConsoleColor::yellow };
public:
	DinoPark(int width, int height, int cellSize, int countColors) {
		_cellsXCount = width;
		_cellsYCount = height;
		_cellSize = cellSize;
		for (int i = 0; i < countColors; i++)
		{
			
			_colors.push_back(fcolors[rand() % fcolors.size()]());
		}
	}

	// Этот метод проверяет, что находится в клетке:
	// -1 - снеговик
	//  0 - пусто
	//  1 - дерево
	//  2 - динозавр
	int find(int x, int y) {
		for (int i = 0; i < _snowmen.size(); i++) {
			if (_snowmen[i].isInside(x, y))
				return -1;
		}
		for (int i = 0; i < _trees.size(); i++) {
			if (_trees[i].isInside(x, y))
				return 1;
		}
		for (int i = 0; i < _hDino.size(); i++) {
			if (_hDino[i].isInside(x, y))
				return 2;
		}
		for (int i = 0; i < _pits.size(); i++)
		{
			if (_pits[i].isInside(x, y))
				return 3;
		}
		return 0;
	}

	// Метод для отрисовки всего поля
	void draw(ConsoleDrawer& cd) {
		// Рисуем сетку
		for (int i = 0; i <= _cellsXCount; i++) {
			int x = i * _cellSize;
			int y = _cellsYCount * _cellSize;
			cd.drawLine(Point(x, 0), Point(x, y), ConsoleColor::black());
		}
		for (int i = 0; i <= _cellsYCount; i++) {
			int x = _cellsXCount * _cellSize;
			int y = i * _cellSize;
			cd.drawLine(Point(0, y), Point(x, y), ConsoleColor::black());
		}

		// Рисуем снеговиков
		for (int i = 0; i < _snowmen.size(); i++) {
			_snowmen[i].draw(cd);
		}

		// Рисуем деревья
		for (int i = 0; i < _trees.size(); i++) {
			_trees[i].draw(cd);
		}

		for (int i = 0; i < _pits.size(); i++) {
			_pits[i].draw(cd);
		}
		// Рисуем динозавра
		for (int i = 0; i < _hDino.size(); i++) {
			_hDino[i].draw(cd);
			_hDino[i].drawHealth(cd, 5 * _cellSize, (_cellsYCount + 1 + i) * _cellSize);
		}
		for (int i = 0; i < _colors.size(); i++) {
			cd.drawCircle(Point(10 * _cellSize + i * _cellSize, (_cellsYCount + 1) * _cellSize), 20, _colors[i], true);
		}
	}

	// Метод обработки вашего хода
	void step(ConsoleDrawer& cd) {

		// Пока ходит только счастливый динозавр

		// Ловим нажатие на клавиатуру
		KEY_EVENT_RECORD key;
		INPUT_RECORD irec[100];
		DWORD cc;

		ReadConsoleInput(cd.get_conHandle(), irec, 100, &cc);
		for (DWORD j = 0; j < cc; ++j) {
			if (irec[j].EventType == KEY_EVENT && irec[j].Event.KeyEvent.bKeyDown) {

				for (int i = 0; i < _hDino.size(); i++) {
					// Смотрим по сторонам
					// -1 - снеговик
					//  0 - пусто
					//  1 - дерево
					//  2 - динозавр
					vector<int> res = {
						lookLeft(_hDino[i].getCellX(), _hDino[i].getCellY()),
						lookUp(_hDino[i].getCellX(), _hDino[i].getCellY()),
						lookRight(_hDino[i].getCellX(), _hDino[i].getCellY()),
						lookDown(_hDino[i].getCellX(), _hDino[i].getCellY())
					};
					// Проверяем, какая именно кнопка была нажата
					switch (irec[j].Event.KeyEvent.wVirtualKeyCode) {
					case VK_LEFT:
						// если путь свободен, идем
						if (res[0] != -1) {
							_hDino[i].step(0);
							// если мы на что-то наступили (пока что только дерево), обновляем картину
							if (res[0] != 0) {
								refresh(cd);
							}
						}
						break;
					case VK_UP:
						if (res[1] != -1) {
							_hDino[i].step(1);
							if (res[1] != 0) {
								refresh(cd);
							}
						}
						break;
					case VK_RIGHT:
						if (res[2] != -1) {
							_hDino[i].step(2);
							if (res[2] != 0) {
								refresh(cd);
							}
						}
						break;
					case VK_DOWN:
						if (res[3] != -1) {
							_hDino[i].step(3);
							if (res[3] != 0) {
								refresh(cd);
							}
						}
						break;
					case VK_ESCAPE:
						cd.stop();
						break;
					}

				}

			}
		}
	}

	void addSnowMan(int x, int y) {
		_snowmen.push_back(SnowMan(x, y, _cellSize));
	}

	void addTree(int x, int y, COLORREF color) {
		_trees.push_back(Tree(x, y, _cellSize, color));
	}

	void addPit(int x, int y) {
		_pits.push_back(Pit(x, y, _cellSize));
	}

	void addHappyDino(int x, int y) {
		_hDino.push_back(HappyDino(x, y, _cellSize));
	}

	// Взгляд на клетку вверх
	int lookUp(int cellX, int cellY) {
		if (cellY == 0)
			return -1;
		return find(cellX, cellY - 1);
	}

	// Взгляд на клетку вниз
	int lookDown(int cellX, int cellY) {
		if (cellY == _cellsYCount - 1)
			return -1;
		return find(cellX, cellY + 1);
	}

	// Взгляд на клетку вправо
	int lookRight(int cellX, int cellY) {
		if (cellX == _cellsXCount - 1)
			return -1;
		return find(cellX + 1, cellY);
	}

	// Взгляд на клетку влево
	int lookLeft(int cellX, int cellY) {
		if (cellX == 0)
			return -1;
		return find(cellX - 1, cellY);
	}

	// Обновляем картину
	void refresh(ConsoleDrawer& cd) {
		for (int i = 0; i < _hDino.size(); i++) {
			// Смотрим, где стоит динозавр
			int x = _hDino[i].getCellX();
			int y = _hDino[i].getCellY();
			for (int j = 0; j < _pits.size(); j++)
			{
				if (_pits[j].isInside(x, y)) {
					_hDino[i].health()--;
					if (_hDino[i].health() == 0) {
						cd.clearScreen();
						cd.stop();
						cout << "Game over" << endl << "Your level: " << _hDino[i].level();
					}
				}
			}
			// Находим то дерево, на котором он стоит
			for (int j = 0; j < _trees.size(); j++) {
				if (_trees[j].isInside(x, y)) {
					if (_trees[j].color() == _colors[0]) {
						_hDino[i].level()++;
						_colors.erase(_colors.begin());
						_colors.push_back(fcolors[rand() % fcolors.size()]());
					}
					else {
						_hDino[i].health()--;
						if (_hDino[i].health()==0) {
							cd.clearScreen();
							cd.stop();
							cout << "Game over" << endl << "Your level: " << _hDino[i].level();
						}
					}
					// Переносим дерево в другое место
					// Цикл нужен, чтобы не попасть в место, которое уже занято
					for (int k = 0; k < 100; k++) {
						int _x = rand() % _cellsXCount;
						int _y = rand() % _cellsYCount;
						if (find(_x, _y) == 0) {
							_trees[j] = Tree(_x, _y, _cellSize, _trees[j].color());
							break;
						}
					}
				}
			}
		}
	}

};

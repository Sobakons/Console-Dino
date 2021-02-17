#include <Windows.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <ctime>
#include <unordered_map>

// Отсюда брать цвета

class ConsoleColor {
public:
	static COLORREF red() { return RGB(255, 0, 0); }
	static COLORREF blue() { return RGB(0, 0, 255); }
	static COLORREF gray() { return RGB(105, 135, 110); }
	static COLORREF white() { return RGB(255, 255, 255); }
	static COLORREF green() { return RGB(0, 255, 0); }
	static COLORREF black() { return RGB(0, 0, 0); }
	static COLORREF brown() { return RGB(80, 20, 25); }
	static COLORREF yellow() { return RGB(255, 255, 0); }
};

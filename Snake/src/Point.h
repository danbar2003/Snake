#pragma once
#include <Windows.h>
#include "Constants.h"

class Point
{

protected:

	const static int PIXEL_SIZE = C_PIXEL_SIZE;
	int m_x, m_y;
public:
	const static HDC WINDOW;

public:

	Point(int x, int y);

	int GetX();

	int GetY();

	void Print(const COLORREF& color);

	bool Merge(Point& other);

	void Delete();

	void SetCoordinate(int x, int y);
};


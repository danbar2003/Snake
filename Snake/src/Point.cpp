#include<iostream>

#include "Point.h"
#include "Constants.h"


const HDC Point::WINDOW = C_WINDOW;

Point::Point(int x, int y)
	:m_x(PIXEL_SIZE * x), m_y(PIXEL_SIZE * y) {
}

void Point::Print(const COLORREF& color)
{
	for (int i = 0; i < PIXEL_SIZE; i++)
		for (int j = 0; j < PIXEL_SIZE; j++)
			SetPixel(WINDOW, m_x + i, m_y + j, color);
}

bool Point::Merge(Point& other)
{
	return m_x == other.m_x && m_y == other.m_y;
}

void Point::Delete()
{
	Print(C_DELETE_COLOR);
}

void Point::SetCoordinate(int x, int y)
{
	m_x = PIXEL_SIZE * x;
	m_y = PIXEL_SIZE * y;
}

int Point::GetX()
{
	return m_x / PIXEL_SIZE;
}

int Point::GetY()
{
	return m_y / PIXEL_SIZE;
}
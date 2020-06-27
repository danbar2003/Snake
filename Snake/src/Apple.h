#pragma once
#include<Windows.h>
#include"Point.h"

class Apple : public Point
{
public:
	const static COLORREF APPLE_COLOR = C_APPLE_COLOR;

	Apple();	

	void Show();
};
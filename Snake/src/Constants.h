#pragma once
#include <windows.h>

const static int WIDTH = 80;
const static int HEIGHT = 50;
const static int M_WIDTH = WIDTH / 2;
const static int M_HEIGHT = HEIGHT / 2;

const static int C_SNAKE_SIZE = 3;
const static int C_PIXEL_SIZE = 10;

const static COLORREF C_APPLE_COLOR = RGB(255, 0, 0);
const static COLORREF C_HEAD_COLOR = RGB(255, 128, 0);
const static COLORREF C_SNAKE_COLOR = RGB(255, 255, 255);
const static COLORREF C_BORDER_COLOR = RGB(0, 255, 0);

const static HDC C_WINDOW = GetDC(GetConsoleWindow());
const static int DELAY_TIME = 50;

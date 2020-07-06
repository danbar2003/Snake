#include<iostream>
#include "Apple.h"
#include"Constants.h"

Apple::Apple()
	:Point(rand() % WIDTH + 1, rand() % HEIGHT) {
	//TODO - generate check (not on snake)
}

void Apple::Show()
{
	Print(APPLE_COLOR);
}

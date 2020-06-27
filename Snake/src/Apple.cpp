#include<iostream>
#include "Apple.h"
#include"Constants.h"

Apple::Apple()
	:Point((rand() % WIDTH), (rand() % HEIGHT)) {
	//TODO - generate check (not on snake)
}

void Apple::Show()
{
	Print(APPLE_COLOR);
}

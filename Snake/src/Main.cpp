#include<iostream>
#include<windows.h>
#include<time.h>

#include "Apple.h"
#include "Snake.h"
#include "Constants.h"

void PrintEdges()
{
	for (int i = 0; i < C_PIXEL_SIZE * WIDTH; i++) {
		SetPixel(C_WINDOW, i, 0, C_BORDER_COLOR);
		SetPixel(C_WINDOW, i, C_PIXEL_SIZE * HEIGHT, C_BORDER_COLOR);
	}
	for (int i = 0; i < C_PIXEL_SIZE * HEIGHT; i++)
	{
		SetPixel(C_WINDOW, 0, i, C_BORDER_COLOR);
		SetPixel(C_WINDOW, C_PIXEL_SIZE * WIDTH, i, C_BORDER_COLOR);

	}
		
}

void Delay(int number_of_mili_seconds)
{
	// Converting time into milli_seconds 
	int milli_seconds = number_of_mili_seconds;

	// Storing start time 
	clock_t start_time = clock();

	// looping till required time is not achieved 
	while (clock() < start_time + milli_seconds)
		;
}

int main()
{
	srand(time(0));
	SnakeNode* head = new SnakeNode(M_WIDTH, M_HEIGHT);
	Snake* const s = new Snake(head, Direction::LEFT, C_SNAKE_SIZE);
	Apple apple;

	while (true)
	{
		s->Move();
		if (s->CheckIfDead())
			break;
		if (s->UpdateDirection())
			break;
		s->Eat(apple);
		PrintEdges();
		apple.Show();
		s->Show();
		Delay(DELAY_TIME);
		
	}
	delete s;
}
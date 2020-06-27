#pragma once
#include "SnakeNode.h"
#include "Apple.h"

enum class Direction
{
	UP, DOWN, LEFT, RIGHT, QUIT = -1
};

class Snake
{
private:
	Direction m_snakeDirection;
	
public:
	SnakeNode* m_head;
	
	Snake(SnakeNode* headm, Direction direction, int size);

	Snake(SnakeNode* head, Direction direction);

	void Move();

	bool UpdateDirection();
	
	void Show();

	void Eat(Apple& apple);

	bool CheckIfDead();

};
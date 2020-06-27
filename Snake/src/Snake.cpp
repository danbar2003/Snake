#include<iostream>
#include<conio.h>

#include "Snake.h"
#include "Constants.h"

Snake::Snake(SnakeNode* head, Direction direction)
	:m_head(head), m_snakeDirection(direction) {}

Snake::Snake(SnakeNode* head, Direction direction, int size)
	: m_head(head), m_snakeDirection(direction)
{
	size -= 1;
	SnakeNode* temp = head;
	
	for (int i = 0; i < size; i++)
	{
		if (m_snakeDirection == Direction::UP) 
			temp->SetNext(new SnakeNode(temp->GetX(), temp->GetY() + 1));
		if (m_snakeDirection == Direction::DOWN)
			temp->SetNext(new SnakeNode(temp->GetX(), temp->GetY() - 1));
		if (m_snakeDirection == Direction::RIGHT)
			temp->SetNext(new SnakeNode(temp->GetX() - 1, temp->GetY()));
		if (m_snakeDirection == Direction::LEFT)
			temp->SetNext(new SnakeNode(temp->GetX() + 1, temp->GetY()));
		temp = temp->GetNext();
	}
}

void Snake::Move()
{

	SnakeNode* temp = m_head;
	SnakeNode* futureFirst;

	while (temp->HasNext()) {
		if (temp->GetNext()->HasNext())
			temp = temp->GetNext();
		else
			break;
	}
	
	futureFirst = temp->GetNext();
	
	if (futureFirst == nullptr)
		return;

	temp->SetNext(nullptr);
	futureFirst->SetNext(m_head);
	futureFirst->Delete();
	switch (m_snakeDirection)
	{
	case Direction::UP:
		futureFirst->SetCoordinate(m_head->GetX(), m_head->GetY() - 1);
		break;
	case Direction::DOWN:
		futureFirst->SetCoordinate(m_head->GetX(), m_head->GetY() + 1);
		break;
	case Direction::LEFT:
		futureFirst->SetCoordinate(m_head->GetX() - 1, m_head->GetY());
		break;
	case Direction::RIGHT:
		futureFirst->SetCoordinate(m_head->GetX() + 1, m_head->GetY());
		break;
	}
	m_head = futureFirst;
}

bool Snake::UpdateDirection()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'w':
			if (m_snakeDirection != Direction::DOWN)
				m_snakeDirection = Direction::UP;
			break;
		case 'a':
			if (m_snakeDirection != Direction::RIGHT)
				m_snakeDirection = Direction::LEFT;
			break;
		case 's':
			if (m_snakeDirection != Direction::UP)
				m_snakeDirection = Direction::DOWN;
			break;
		case 'd':
			if (m_snakeDirection != Direction::LEFT)
				m_snakeDirection = Direction::RIGHT;
			break;
		case 'q':
			m_snakeDirection = Direction::QUIT;
			return true;
		}
	}
	return false;
}

void Snake::Show()
{
	//print the new head
	SnakeNode* temp = m_head;
	temp->Print(C_HEAD_COLOR);
	//print the old head as white
	if (temp->HasNext()) {
		temp = temp->GetNext();
		temp->Print(C_SNAKE_COLOR);
	}
	
}

void Snake::Eat(Apple& apple)
{
	if (apple.Merge(*m_head))
	{
		SnakeNode* temp = m_head;
		while (temp->HasNext())
			temp = temp->GetNext();
		temp->SetNext(new SnakeNode());
		apple.Delete();
		apple.SetCoordinate(rand() % WIDTH, rand() % HEIGHT);
	}
}

bool TouchBorder(SnakeNode& head)
{
	if (head.GetX() == 0 || head.GetX() == WIDTH
		|| head.GetY() == 0 || head.GetY() == HEIGHT)
		return true;
	return false;
		
}

bool Snake::CheckIfDead()
{
	SnakeNode* temp = m_head;
	if (TouchBorder(*m_head))
		return true;
	temp = temp->GetNext();
	while (temp != nullptr)
	{
		if (temp->Merge(*m_head))
			return true;
		temp = temp->GetNext();
	}
	return false;
}


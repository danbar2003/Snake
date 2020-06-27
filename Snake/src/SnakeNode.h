#pragma once
#include"Point.h"

class SnakeNode : public Point
{
private:
	SnakeNode* m_nextNode;
public:

	SnakeNode();

	SnakeNode(int x, int y);

	SnakeNode* GetNext();

	void SetNext(SnakeNode* nextNode);

	bool HasNext();

	~SnakeNode();

};

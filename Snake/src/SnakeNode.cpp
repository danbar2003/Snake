#include<iostream>
#include "SnakeNode.h"

SnakeNode::SnakeNode()
	:Point(0,0), m_nextNode(nullptr) {}

SnakeNode::SnakeNode(int x, int y)
	:Point(x, y), m_nextNode(nullptr){}

SnakeNode::~SnakeNode()
{
	std::cout << "D" << std::endl;
	delete m_nextNode;
}

SnakeNode* SnakeNode::GetNext()
{
	return m_nextNode;
}

void SnakeNode::SetNext(SnakeNode* nextNode) 
{
	m_nextNode = nextNode;
}

bool SnakeNode::HasNext()
{
	return m_nextNode != nullptr;
}

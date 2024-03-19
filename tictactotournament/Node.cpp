#include "Node.h"

Node::Node() : next(nullptr), HighScore(nullptr)
{

}

Node::Node(HighScore* newHighScore) : next(nullptr), HighScore(nullptr)
{
	this->HighScore = newHighScore;
}
Node::~Node()
{
	delete HighScore;
	HighScore = nullptr;

	next = nullptr;
}

//Getters
HighScore* Node::GetHighScore()
{
	return HighScore;
}

Node* Node::GetNextNode()
{
	return next;
}

//Setters
void Node::SetNextNode(Node* nextNode)
{
	next = nextNode;
}

void Node::SetHighScore(HighScore* newHighScore)
{
	HighScore = newHighScore;
}
#pragma once

#include "HighScore.h"

class Node
{
private:
	Node* next;
	HighScore* player;

public:
	Node();
	Node(HighScore* data);
	~Node();

	//Getters
	Node* GetNextNode();
	HighScore* GetHighScore();

	//Setters
	void SetNextNode(Node* nextNode);
	void SetHighScore(HighScore* newHighScore);
};
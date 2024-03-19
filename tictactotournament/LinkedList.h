#pragma once

#include "HighScore.h"
#include "Node.h"

#include <cstring>

class LinkedList
{
private:
	Node* head;

	void Append(HighScore* data);

public:
	//Manager Functions
	LinkedList();
	~LinkedList();
	LinkedList(const LinkedList& copy);
	LinkedList& operator=(const LinkedList& rhs);

	//List Management functions
	void InsertOrdered(HighScore* data);
	void Prepend(HighScore* data);

	void Purge();

	void Display();

	void UpdateHighScore(const int* HighScoreName, HighScore* update);
	void DeleteHighScore(const int* HighScoreName);
};
#include "LinkedList.h"

LinkedList::LinkedList() : head(nullptr)
{

}

LinkedList::~LinkedList()
{
	Purge();
}

LinkedList::LinkedList(const LinkedList& copy) : head(nullptr)
{
	Node* travel = copy.head;

	while (travel != nullptr)
	{
		Append(travel->GetHighScore());
		travel = travel->GetNextNode();
	}
}


LinkedList& LinkedList::operator=(const LinkedList& rhs)
{
	this->Purge();

	Node* travel = rhs.head;
	while (travel != nullptr)
	{
		Append(travel->GetHighScore());
		travel = travel->GetNextNode();
	}

	return *this;
}

void LinkedList::InsertOrdered(HighScore* data)
{
	Node* newNode = new Node(data);

	if (head == nullptr || (_stricmp(newNode->GetHighScore()->GetNumberWins(), head->GetHighScore()->GetNumberWins()) > 0))
	{
		newNode->SetNextNode(head);
		head = newNode;
	}
	else
	{
		Node* travel = head;
		Node* trail = nullptr;
		while (travel != nullptr && (_stricmp(newNode->GetHighScore()->GetNumberWins(), travel->GetHighScore()->GetNumberWins()) <= 0))
		{
			trail = travel;
			travel = travel->GetNextNode();
		}

		trail->SetNextNode(newNode);
		newNode->SetNextNode(travel);
	}

}

void LinkedList::Append(HighScore* data)
{
	HighScore* newHighScore = new HighScore(*data);
	Node* newNode = new Node(newHighScore);

	if (head == nullptr)
	{
		head = newNode;
	}
	else
	{
		Node* travel = head;

		while (travel->GetNextNode() != nullptr)
		{
			travel = travel->GetNextNode();
		}

		travel->SetNextNode(newNode);
	}
}

void LinkedList::Prepend(HighScore* data)
{
	Node* newNode = new Node(data);

	newNode->SetNextNode(head);
	head = newNode;
}

void LinkedList::Purge()
{
	Node* trail = nullptr;

	while (head != nullptr)
	{
		trail = head;
		head = head->GetNextNode();

		delete trail;
	}
}

void LinkedList::Display()
{
	cout << "***** HighScore List Start ******" << endl;

	Node* travel = head;

	while (travel != nullptr)
	{
		travel->GetHighScore()->Display();
		travel = travel->GetNextNode();
	}

	cout << " ***** HighScore List End *****" << endl;
}

void LinkedList::UpdateHighScore(const int* HighScoreName, HighScore* update)
{
	Node* travel = head;

	//find HighScore
	while (travel != nullptr && _stricmp(travel->GetHighScore()->GetNumberWins(), HighScoreName) != 0)
	{
		travel = travel->GetNextNode();
	}

	//found HighScore
	if (travel != nullptr)
	{
		travel->SetHighScore(update);
	}
}

void LinkedList::DeleteHighScore(const int* HighScoreName)
{
	//find the HighScore
	Node* travel = head;
	Node* trail = nullptr;

	while (travel != nullptr && _stricmp(travel->GetHighScore()->GetNumberWins(), HighScoreName) != 0)
	{
		trail = travel;
		travel = travel->GetNextNode();
	}

	//found HighScore
	if (travel != nullptr)
	{
		if (travel == head)
		{
			head = travel->GetNextNode();
		}
		else if (trail != nullptr) // not necessary, but can be used
		{
			trail->SetNextNode(travel->GetNextNode());
		}

		delete travel;
	}
}
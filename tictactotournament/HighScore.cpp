#include "HighScore.h"

HighScore::HighScore() : Name(nullptr), Champion(nullptr), NumberWins(0)
{

}

HighScore::HighScore(const char* name, const char* Champion, unsigned short NumberWins) : Name(nullptr), Champion(nullptr), NumberWins(NumberWins)
{
	if (name != nullptr)
	{
		int length = strlen(name);
		Name = new char[length + 1] {0};
		strcpy_s(Name, length + 1, name);
	}

	if (Champion != nullptr)
	{
		int length = strlen(Champion);
		Champion = new char[length + 1] {0};
		strcpy_s(Champion, length + 1, Champion);
	}
}

HighScore::~HighScore()
{
	delete[] Name;
	Name = nullptr;

	delete[] Champion;
	Champion = nullptr;
}

HighScore::HighScore(const HighScore& copy) : Name(nullptr), Champion(nullptr), NumberWins(copy.NumberWins)
{
	if (copy.Name != nullptr)
	{
		int length = strlen(copy.Name);
		Name = new char[length + 1] {0};
		strcpy_s(Name, length + 1, copy.Name);
	}

	if (copy.Champion != nullptr)
	{
		int length = strlen(copy.Champion);
		Champion = new char[length + 1] {0};
		strcpy_s(Champion, length + 1, copy.Champion);
	}
}

HighScore& HighScore::operator=(const HighScore& rhs)
{
	NumberWins = rhs.NumberWins;

	if (rhs.Name != nullptr)
	{
		int length = strlen(rhs.Name);
		Name = new char[length + 1] {0};
		strcpy_s(Name, length + 1, rhs.Name);
	}

	if (rhs.Champion != nullptr)
	{
		int length = strlen(rhs.Champion);
		Champion = new char[length + 1] {0};
		strcpy_s(Champion, length + 1, rhs.Champion);
	}

	return *this;
}

//Getters
char* HighScore::GetName()
{
	return Name;
}

char* HighScore::GetChampion()
{
	return Champion;
}

unsigned short HighScore::GetNumberWins()
{
	return NumberWins;
}

//Setters
void HighScore::SetName(const char* name)
{
	delete[] Name;
	Name = nullptr;

	if (name != nullptr)
	{
		int length = strlen(name);
		Name = new char[length + 1] {0};
		strcpy_s(Name, length + 1, name);
	}
}

void HighScore::SetChampion(char* Champion)
{
	delete[] Champion;
	Champion = nullptr;

	if (Champion != nullptr)
	{
		int length = strlen(Champion);
		Champion = new char[length + 1] {0};
		strcpy_s(Champion, length + 1, Champion);
	}
}

void HighScore::SetNumberWins(unsigned short NumberWins)
{
	if (NumberWins > 0)
	{
		NumberWins = NumberWins;
	}
}

void HighScore::Display()
{
	cout << left << setw(30) << Name << setw(30) << NumberWins << setw(30) << Champion << endl;
}
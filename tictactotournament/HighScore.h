#pragma once

#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

#include <string>
using std::string;

#include <iomanip>
using std::left;
using std::setw;

class HighScore
{
private:
	char* Name;
	unsigned short NumberWins;
	char* Champion;

public:
	//Manager Functions
	HighScore();
	HighScore(const char* name, const char* Champion, unsigned short NumberWins);
	~HighScore();
	HighScore(const HighScore& copy);
	HighScore& operator=(const HighScore& rhs);

	//Getters
	char* GetName();
	char* GetChampion();
	unsigned short GetNumberWins();

	//Setters
	void SetName(const char* name);
	void SetChampion(char* Champion);
	void SetNumberWins(unsigned short NumberWins);

	//Other Functions
	void Display();

};
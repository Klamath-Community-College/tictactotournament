#pragma once
// Class for creating and maintaining instance(s) of game
#include "Player.h"

class Game
{
	private:
		char m_Difficulty;		// to set game type
		int m_Countdown;		// for PVP option
		int m_Tracker;			// for tracking consecutive games

	public:
		// manager functions
		Game();											// default ctor
		Game(char diff, int count, int track);			// 3-arg ctor
		Game(Game& copy);								// copy ctor
		Game operator=(Game& rhs);						// op=
		~Game();										// dtor

		// getters
		char GetDifficulty() const;
		int GetCountdown() const;
		int GetTracker() const;

		// setters
		void SetDifficulty(char diff);
		void SetCountdown(int count);
		void SetTracker(int track);

		bool TestDraw();
		bool GameOver();
		void ClaimSpace(Player player, char input);
		void DisplayBoard(char* ptr);
		void PlayGame();
};


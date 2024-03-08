#pragma once
// Class for creating and maintaining instance(s) of game
#include "Player.h"

class Game
{
	private:
		char m_Difficulty;		// to set game type
		int m_Countdown;		// for PVP option
		int m_Tracker;			// for tracking consecutive games

		//Player m_Player1;		// for tracking p1
		//Player m_Player2;		// for tracking p2

	public:
		// manager functions
		Game();											// default ctor
		Game(char diff, int count, int track);			// 3-arg ctor
		Game(Game& copy);
		Game operator=(Game& rhs);
		~Game();										// dtor

		// getters
		char GetDifficulty() const;
		int GetCountdown() const;
		int GetTracker() const;
		//Player m_Player1() const;
		//Player m_Player2() const;

		// setters
		void SetDifficulty(char diff);
		void SetCountdown(int count);
		void SetTracker(int track);

		bool TestDraw();
		bool GameOver();
		void ClaimSpace(Player player, char input);
		void DisplayBoard(char* ptr);
		void DisplayMenu_Main();
		void PlayGame();
};


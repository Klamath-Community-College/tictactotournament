#pragma once
// Class for creating and maintaining instance(s) of game
#include "Player.h"

class Game
{
	private:
		char m_Board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
		char m_Difficulty;		// to set game type
		int m_Countdown;		// for PVP option
		int m_Tracker;			// for tracking consecutive games
		Player player1;
		Player player2;

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
		char GetSpace(int space) const;

		// setters
		void SetDifficulty(char diff);
		void SetCountdown(int count);
		void SetTracker(int track);
		void SetSpace(int space, Player player);

		bool TestDraw();
		bool GameOver();
		void ClaimSpace(Player playerOn, Player playerOff, char input);
		void DisplayBoard();
		void PlayGame(bool tourney);
		void SetOptions(Game game, bool tourney);
};

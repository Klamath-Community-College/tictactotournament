#pragma once
#include "Champion.h"

// Class for creating and maintaining instance(s) of players including AI

class Player
{
	private:
		Champion m_Champion;	// create instance of champion class
		int m_Wins;				// for tracking total wins
		char m_Token;			// X or O
		bool m_Player;			// for player or AI

	public:
		// manager functions
		Player();
		Player(bool player, char token, int wins);
		Player(Player& copy);
		Player operator=(Player& rhs);
		~Player();

		// getters
		bool GetPlayer() const;
		char GetToken() const;
		int GetWins() const;
		Champion GetChampion();

		// setters
		void SetPlayer(bool player);
		void SetToken(char token);
		void SetWins(int wins);
		void SetChampion(Champion champ);

};


#pragma once
// Class for creating and maintaining instance(s) of players including AI

class Player
{
	private:
		char m_Champion;		// chosen champion W, A or R
		int m_Wins;				// for tracking total wins
		char m_Token;			// X or O
		bool m_Player;			// for player or AI

	public:
		// manager functions
		Player();
		Player(bool player, char token, int wins, char champ);
		Player(Player& copy);
		Player operator=(Player& rhs);
		~Player();

		// getters
		bool GetPlayer() const;
		char GetToken() const;
		int GetWins() const;
		char GetChampion() const;

		// setters
		void SetPlayer(bool player);
		void SetToken(char token);
		void SetWins(int wins);
		void SetChampion(char champ);

};


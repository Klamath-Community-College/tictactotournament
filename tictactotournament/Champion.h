#pragma once
// Class for player pvp over claimed space

class Champion
{
	private:
		int m_Power;
		int m_Mental;
		int m_Agility;
		int m_Health;
		int m_TotalWins;
		char m_Role;			// W-arrior, A-dept, R-ogue, B-beg(AI)?

	public:
		// manager functions
		Champion();
		Champion(int power, int mental, int agility, int health, int wins);
		~Champion();

		// getters
		int GetPower() const;
		int GetMental() const;
		int GetAgility() const;
		int GetHealth() const;
		int GetTotalWins() const;
		int GetRole() const;

		// setters
		void SetPower(int power);
		void SetMental(int mental);
		void SetAgility(int agility);
		void SetHealth(int health);
		void SetTotalWins(int wins);
		void SetRole(char role);

};


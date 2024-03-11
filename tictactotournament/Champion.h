#pragma once
// Class for player pvp over claimed space

/***************************************************************************************
* 
*	Stat bonus = (Stat-10)/2
* 
*	Compare Attack vs Defense(10+Agility Bonus), Damage vs Health(10+Health bonus)
* 
*	Warrior - Power Bonus to Damage
*	Adept   - Mental Bonus to Attack
*	Rogue   - Agility Bonus to Defense (in addition to normal)
* 
*	Should champions be initialized at start or with new game?
*
***************************************************************************************/

class Champion
{
	private:
		int m_Power;
		int m_Mental;
		int m_Agility;
		int m_Health;
		int m_ATT;
		int m_DMG;
		int m_AC;
		int m_HP;
		int m_TotalWins;
		char m_Role;			// W-arrior, A-dept, R-ogue, B-beg(AI)?

	public:
		// manager functions
		Champion();
		Champion(int power, int mental, int agility, int health, int wins);
		Champion(Champion& copy);
		Champion operator=(Champion& rhs);
		~Champion();

		// getters
		int GetPower() const;
		int GetMental() const;
		int GetAgility() const;
		int GetHealth() const;
		int GetTotalWins() const;
		int GetRole() const;
		int GetATT() const;
		int GetDMG() const;
		int GetAC() const;
		int GetHP()const;

		// setters
		void SetPower(int power);
		void SetMental(int mental);
		void SetAgility(int agility);
		void SetHealth(int health);
		void SetTotalWins(int wins);
		void SetRole(char role);
		void SetATT(int att);
		void SetDMG(int dmg);
		void SetAC(int ac);
		void SetHP(int hp);

		void ChallengeSpace(Player defender, Player challenger, int space);
		int GenerateRNG(int min, int max);
};


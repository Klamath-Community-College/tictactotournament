#pragma once
#include "Game.h"
#include "Player.h"

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
		int m_Power = 0;
		int m_Mental = 0;
		int m_Agility = 0;
		int m_Health = 0;
		int m_ATT = 0;				// Attack bonus
		int m_DMG = 0;				// Damage bonus
		int m_AC = 0;				// Armor class
		int m_HP = 0;				// Health Pool
		int m_TotalWins = 0;
		char m_Role = '\0';			// W-arrior, A-dept, R-ogue

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
		char GetRole() const;
		int GetATT() const;
		int GetDMG() const;
		int GetAC() const;
		int GetHP() const;

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

		int GenerateRNG(int min, int max);
};

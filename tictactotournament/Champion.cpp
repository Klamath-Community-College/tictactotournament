#include "Champion.h"
#include "Player.h"
#include <cstdlib>
#include <ctime>

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Default ctor, initializes to base values.
*
******************************************************************************/
Champion::Champion() : m_Power(8), m_Mental(8), m_Agility(8), m_Health(8), m_TotalWins(0), m_Role('\0')
{
	// generate stats
	m_Power = GenerateRNG(3, 18);
	m_Mental = GenerateRNG(3, 18);
	m_Agility = GenerateRNG(3, 18);
	m_Health = GenerateRNG(3, 18);

	// if warrior apply power to damage
	m_Role == 'W' ? m_DMG = (m_Power - 10) / 2 : m_DMG = 0;

	// if adept apply mental to attack
	m_Role == 'A' ? m_ATT = (m_Mental - 10) / 2 : m_ATT = 0;

	// if rogue apply agility to armor twice, if not apply once
	m_Role == 'R' ? m_AC = ((m_Agility - 10) / 2) * 2 : (m_Agility - 10) / 2;

	// initialize health pool and adjust for health bonus
	m_HP = 8 + ((m_Health - 10) / 2);
}

/******************************************************************************
* Entry: int power, int mental, int agility, int health, int wins
*
* Exit: Nothing
*
* Purpose: Argument ctor, initializes values to base value or according to what
*			is passed in.
*
******************************************************************************/
Champion::Champion(int power, int mental, int agility, int health, int wins) : m_Power(8), m_Mental(8), m_Agility(8), m_Health(8), m_TotalWins(0), m_Role('\0')
{
	m_Power = power;
	m_Mental = mental;
	m_Agility = agility;
	m_Health = health;
	m_TotalWins = wins;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Copy constructor, creates new object by copying properties
*
******************************************************************************/
Champion::Champion(Champion& copy)
{
	m_Power = copy.m_Power;
	m_Mental = copy.m_Mental;
	m_Agility = copy.m_Agility;
	m_Health = copy.m_Health;
	m_TotalWins = copy.m_TotalWins;
	m_Role = copy.m_Role;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Operator =
*
******************************************************************************/
Champion Champion::operator=(Champion& rhs)
{
	m_Power = rhs.m_Power;
	m_Mental = rhs.m_Mental;
	m_Agility = rhs.m_Agility;
	m_Health = rhs.m_Health;
	m_TotalWins = rhs.m_TotalWins;
	m_Role = rhs.m_Role;

	return *this;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Destructor
*
******************************************************************************/
Champion::~Champion()
{
}

/******************************************************************************
* Entry: Nothing
*
* Exit: m_Power
*
* Purpose: Returns value of Power stat
*
******************************************************************************/
int Champion::GetPower() const
{
	return m_Power;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: m_Mental
*
* Purpose: Returns value of Mental stat
*
******************************************************************************/
int Champion::GetMental() const
{
	return m_Mental;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: m_Agility
*
* Purpose: returns value of Agility stat
*
******************************************************************************/
int Champion::GetAgility() const
{
	return m_Agility;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: m_Health
*
* Purpose: Returns value of Health stat
*
******************************************************************************/
int Champion::GetHealth() const
{
	return m_Health;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: m_ATT
*
* Purpose: Returns value of attack bonus
*
******************************************************************************/
int Champion::GetATT() const
{
	return m_ATT;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: m_DMG
*
* Purpose: Returns value of damage bonus
*
******************************************************************************/
int Champion::GetDMG() const
{
	return m_DMG;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: m_AC
*
* Purpose: Returns value of Armor class
*
******************************************************************************/
int Champion::GetAC() const
{
	return m_AC;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: m_HP
*
* Purpose: Returns value of Health Pool
*
******************************************************************************/
int Champion::GetHP() const
{
	return m_HP;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: m_TotalWins
*
* Purpose: Returns value of Total wins accrued by role.
*
******************************************************************************/
int Champion::GetTotalWins() const
{
	return m_TotalWins;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: m_Role
*
* Purpose: Returns value defining role of champion.
*
******************************************************************************/
int Champion::GetRole() const
{
	return m_Role;
}

/******************************************************************************
* Entry: int power
*
* Exit: Nothing
*
* Purpose: Sets value of Power stat.
*
******************************************************************************/
void Champion::SetPower(int power)
{
	m_Power = power;
}

/******************************************************************************
* Entry: int mental
*
* Exit: Nothing
*
* Purpose: Sets value of Mental stat.
*
******************************************************************************/
void Champion::SetMental(int mental)
{
	m_Mental = mental;
}

/******************************************************************************
* Entry: int agility
*
* Exit: Nothing
*
* Purpose: Sets value of Agiliity stat.
*
******************************************************************************/
void Champion::SetAgility(int agility)
{
	m_Agility = agility;
}

/******************************************************************************
* Entry: int health
*
* Exit: Nothing
*
* Purpose: sets value of Health stat.
*
******************************************************************************/
void Champion::SetHealth(int health)
{
	m_Health = health;
}

/******************************************************************************
* Entry: int wins
*
* Exit: Nothing
*
* Purpose: Sets value of Total Wins accumulator.
*
******************************************************************************/
void Champion::SetTotalWins(int wins)
{
	m_TotalWins = wins;
}

/******************************************************************************
* Entry: char role
*
* Exit: Nothing
*
* Purpose: Sets value of champion role.
*
******************************************************************************/
void Champion::SetRole(char role)
{
	m_Role = role;
}

/******************************************************************************
* Entry: int att
*
* Exit: Nothing
*
* Purpose: Sets value of attack bonus
*
******************************************************************************/
void Champion::SetATT(int att)
{
	m_ATT = att;
}

/******************************************************************************
* Entry: int dmg
*
* Exit: Nothing
*
* Purpose: Sets value of damage bonus
*
******************************************************************************/
void Champion::SetDMG(int dmg)
{
	m_DMG = dmg;
}

/******************************************************************************
* Entry: int ac
*
* Exit: Nothing
*
* Purpose: Sets value of armor class
*
******************************************************************************/
void Champion::SetAC(int ac)
{
	m_AC = ac;
}

/******************************************************************************
* Entry: int hp
*
* Exit: Nothing
*
* Purpose: Sets value of health pool
*
******************************************************************************/
void Champion::SetHP(int hp)
{
	m_HP = hp;
}

void ChallengeSpace(Player defender, Player challenger, int space)
{
	int tempAttack = 0;

	while (defender.GetChampion().GetHP() != 0 || challenger.GetChampion().GetHP() != 0)
	{
		tempAttack = challenger.GetChampion().GetATT() + challenger.GetChampion().GenerateRNG(1, 6);
		tempAttack > defender.GetChampion().GetAC() ? defender.GetChampion().SetHP(defender.GetChampion().GetHP() -
			challenger.GetChampion().GetDMG()) : defender.GetChampion().SetHP(defender.GetChampion().GetHP() - 0);

		tempAttack = defender.GetChampion().GetATT() + defender.GetChampion().GenerateRNG(1, 6);
		tempAttack > challenger.GetChampion().GetAC() ? challenger.GetChampion().SetHP(challenger.GetChampion().GetHP() -
			defender.GetChampion().GetDMG()) : challenger.GetChampion().SetHP(challenger.GetChampion().GetHP() - 0);
	}

	if (defender.GetChampion().GetHP() == 0)
	{
		// set space to attacker's token
	}
}

int GenerateRNG(int min, int max)
{
	// Providing a seed value
	srand((unsigned)time(NULL));

	// Get a random number
	int random = min + (rand() % max);

	return random;
}
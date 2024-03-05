#include "Champion.h"

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

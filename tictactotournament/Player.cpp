#include "Player.h"

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Default ctor, initializes to base player values
*
******************************************************************************/
Player::Player() : m_Player(true), m_Token('X'), m_Wins(0), m_Champion('W')
{
}

/******************************************************************************
* Entry: bool player, char token, int wins, char champ
*
* Exit: Nothing
*
* Purpose: 4-arg ctor, initializes with arguments or base values if none passed
*
******************************************************************************/
Player::Player(bool player, char token, int wins, char champ) : m_Player(true), m_Token('X'), m_Wins(0), m_Champion('W')
{
	m_Player = player;
	m_Token = token;
	m_Wins = wins;
	m_Champion = champ;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Deconstructor
*
******************************************************************************/
Player::~Player()
{
}

/******************************************************************************
* Entry: Nothing
*
* Exit: m_Player
*
* Purpose: Returns value of player state (person or AI)
*
******************************************************************************/
bool Player::GetPlayer() const
{
	return m_Player;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: m_Token
*
* Purpose: Returns player token representation ( X or O )
*
******************************************************************************/
char Player::GetToken() const
{
	return m_Token;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: m_Wins
*
* Purpose: Returns value stating number of accrued wins by player
*
******************************************************************************/
int Player::GetWins() const
{
	return m_Wins;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: m_Champion
*
* Purpose: Returns value which holds player's choice of champion for PVP
*
******************************************************************************/
char Player::GetChampion() const
{
	return m_Champion;
}

/******************************************************************************
* Entry: bool player
*
* Exit: Nothing
*
* Purpose: Sets value stating if object is a player or AI
*
******************************************************************************/
void Player::SetPlayer(bool player)
{
	m_Player = player;
}

/******************************************************************************
* Entry: char token
*
* Exit: Nothing
*
* Purpose: Sets token to be used by player ( X or O )
*
******************************************************************************/
void Player::SetToken(char token)
{
	m_Token = token;
}

/******************************************************************************
* Entry: int wins
*
* Exit: Nothing
*
* Purpose: Sets value holding number of wins accrued by player
*
******************************************************************************/
void Player::SetWins(int wins)
{
	m_Wins = wins;
}

/******************************************************************************
* Entry: char champ
*
* Exit: Nothing
*
* Purpose: Sets value stating player's choice of champion
*
******************************************************************************/
void Player::SetChampion(char champ)
{
	m_Champion = champ;
}

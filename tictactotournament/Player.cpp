#include "Player.h"
#include "Champion.h"

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Default ctor, initializes to base player values
*
******************************************************************************/
Player::Player() : m_Player(true), m_Token('X'), m_Wins(0)
{
	Champion playerChamp;
}

/******************************************************************************
* Entry: bool player, char token, int wins, char champ
*
* Exit: Nothing
*
* Purpose: 4-arg ctor, initializes with arguments or base values if none passed
*
******************************************************************************/
Player::Player(bool player, char token, int wins) : m_Player(true), m_Token('X'), m_Wins(0)
{
	m_Player = player;
	m_Token = token;
	m_Wins = wins;
	Champion playerChamp;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Copy constructor, creates new object by copying variables
*
******************************************************************************/
Player::Player(Player& copy)
{
	m_Player = copy.m_Player;
	m_Token = copy.m_Token;
	m_Wins = copy.m_Wins;
	m_Champion = copy.m_Champion;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Operator =
*
******************************************************************************/
Player Player::operator=(Player& rhs)
{
	m_Player = rhs.m_Player;
	m_Token = rhs.m_Token;
	m_Wins = rhs.m_Wins;
	m_Champion = rhs.m_Champion;

	return *this;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Destructor, cleans up dynamically created memory
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

Champion Player::GetChampion()
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

void Player::SetChampion(Champion champ)
{

}
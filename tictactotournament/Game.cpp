#include "Game.h"

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Default ctor, initializes game settings to easy mode
*
******************************************************************************/
Game::Game() : m_Difficulty('E'), m_Countdown(0), m_Tracker(1)
{
}

/******************************************************************************
* Entry: char diff, int count, int track
*
* Exit: Nothing
*
* Purpose: Argument ctor, uses default ctor settings or those of arguments
*			passed in.
*
******************************************************************************/
Game::Game(char diff, int count, int track) : m_Difficulty('E'), m_Countdown(0), m_Tracker(1)
{
	m_Difficulty = diff;
	m_Countdown = count;
	m_Tracker = track;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Destructor
*
******************************************************************************/
Game::~Game()
{
}

/******************************************************************************
* Entry: Nothing
*
* Exit: m_Difficulty
*
* Purpose: Returns difficulty setting for game
*
******************************************************************************/
char Game::GetDifficulty() const
{
	return m_Difficulty;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: m_countdown
*
* Purpose: Returns countdown value for game
*
******************************************************************************/
int Game::GetCountdown() const
{
	return m_Countdown;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: m_Tracker
*
* Purpose: Returns value tracking number of games played
*
******************************************************************************/
int Game::GetTracker() const
{
	return m_Tracker;
}

/******************************************************************************
* Entry: char diff
*
* Exit: Nothing
*
* Purpose: Sets difficulty value for game
*
******************************************************************************/
void Game::SetDifficulty(char diff)
{
	m_Difficulty = diff;
}

/******************************************************************************
* Entry: int count
*
* Exit: Nothing
*
* Purpose: Sets value of countdown timer allowing PVP
*
******************************************************************************/
void Game::SetCountdown(int count)
{
	m_Countdown = count;
}

/******************************************************************************
* Entry: int track
*
* Exit: Nothing
*
* Purpose: Sets value counting number of games played.
*
******************************************************************************/
void Game::SetTracker(int track)
{
	m_Tracker = track;
}

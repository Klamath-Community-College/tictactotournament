#include "Game.h"
#include "Player.h"
#include <iostream>
using std::cout;
using std::endl;

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
	// Create board array
	char board[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
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
* Purpose: Copy ctor, creates new game by copying settings
*
******************************************************************************/
Game::Game(Game& copy)
{
	m_Difficulty = copy.m_Difficulty;
	m_Countdown = copy.m_Countdown;
	m_Tracker = copy.m_Tracker;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Copy assignment
*
******************************************************************************/
Game Game::operator=(Game& rhs)
{
	m_Difficulty = rhs.m_Difficulty;
	m_Countdown = rhs.m_Countdown;
	m_Tracker = rhs.m_Tracker;

	return *this;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Destructor, cleans up any dynamically created memory
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

/******************************************************************************
* Entry: Nothing
*
* Exit: Bool result
*
* Purpose: Computes if game is a draw
*
******************************************************************************/
bool Game::TestDraw()
{
    bool draw = false;

    if (ptr[0] != '1' && ptr[1] != '2' && ptr[2] != '3' && ptr[3] != '4' && ptr[4] != '5' && ptr[5] != '6' && ptr[6] != '7'
        && ptr[7] != '8' && ptr[8] != '9')
    {
        draw = true;
    }
    return draw;
}

/******************************************************************************
* Entry: char diff
*
* Exit: Bool result
*
* Purpose: Computes if game has been won
*
******************************************************************************/
bool Game::GameOver()
{
    bool result = false;
   char gameDiff = GetDifficulty();

    if (ptr[0] == ptr[1] == ptr[2] || ptr[3] == ptr[4] == ptr[5] || ptr[6] == ptr[7] == ptr[8])
    {
        // if win is horizontal
        result = true;
    }
    else if (ptr[0] == ptr[3] == ptr[6] || ptr[1] == ptr[4] == ptr[7] || ptr[2] == ptr[5] == ptr[8])
    {
        // if win is vertical
        result = true;
    }
    else if (ptr[0] == ptr[4] == ptr[8] || ptr[2] == ptr[4] == ptr[6])
    {
        // if win is diagonal
        result = true;
    }
    else if (gameDiff == 'E')
    {
        // if all spaces filled on easy (non-combat)
        result = TestDraw();
        cout << "All spaces are filled - game is a draw!";
    }
    else
    {
        // if all spaces filled not on easy (non-combat)
        cout << "All spaces are filled - only victory by combat remains!";
    }

    return result;
}


/******************************************************************************
* Entry: char indicating player choice
*
* Exit: no return
*
* Purpose: Compares player choice to board to see if move is valid
*
******************************************************************************/
void Game::ClaimSpace(Player player, char input)
{
    if (input >= '1' && input <= '9')
    {
        switch (input)
        {
        case '1':
            if (ptr[input - 1] == '1')
            {
                ptr[input - 1] = Player::GetToken();
            }
            else if (ptr[input - 1] != token)
            {
                // call PVP function
            }
            else
            {
                cout << "You have already claimed this space!";
            }
            break;
        case '2':
            if (ptr[input - 1] == '2')
            {
                ptr[input - 1] = token;
            }
            else if (ptr[input - 1] != token)
            {
                // call PVP function
            }
            else
            {
                cout << "You have already claimed this space!";
            }
            break;
        case '3':
            if (ptr[input - 1] == '3')
            {
                ptr[input - 1] = token;
            }
            else if (ptr[input - 1] != token)
            {
                // call PVP function
            }
            else
            {
                cout << "You have already claimed this space!";
            }
            break;
        case '4':
            if (ptr[input - 1] == '4')
            {
                ptr[input - 1] = token;
            }
            else if (ptr[input - 1] != token)
            {
                // call PVP function
            }
            else
            {
                cout << "You have already claimed this space!";
            }
            break;
        case '5':
            if (ptr[input - 1] == '5')
            {
                ptr[input - 1] = token;
            }
            else if (ptr[input - 1] != token)
            {
                // call PVP function
            }
            else
            {
                cout << "You have already claimed this space!";
            }
            break;
        case '6':
            if (ptr[input - 1] == '6')
            {
                ptr[input - 1] = token;
            }
            else if (ptr[input - 1] != token)
            {
                // call PVP function
            }
            else
            {
                cout << "You have already claimed this space!";
            }
            break;
        case '7':
            if (ptr[input - 1] == '7')
            {
                ptr[input - 1] = token;
            }
            else if (ptr[input - 1] != token)
            {
                // call PVP function
            }
            else
            {
                cout << "You have already claimed this space!";
            }
            break;
        case '8':
            if (ptr[input - 1] == '8')
            {
                ptr[input - 1] = token;
            }
            else if (ptr[input - 1] != token)
            {
                // call PVP function
            }
            else
            {
                cout << "You have already claimed this space!";
            }
            break;
        case '9':
            if (ptr[input - 1] == '9')
            {
                ptr[input - 1] = token;
            }
            else if (ptr[input - 1] != token)
            {
                // call PVP function
            }
            else
            {
                cout << "You have already claimed this space!";
            }
            break;
        }
    }
    else
    {
        cout << "Invalid choice." << endl;
    }
}


/******************************************************************************
* Entry: Pointer to gameBoard array (board_ptr)
*
* Exit: No return
*
* Purpose: Displays current state of game using gameBoard array
*
******************************************************************************/
void Game::DisplayBoard(char* ptr)
{
    for (int row = 0; row < 3; row++)                                            // loop for displaying rows
    {
        for (int column = 0; column < 3; column++)                               // loop for displaying columns
        {
            cout << ' ' << *(ptr + column) << ' ';                                 // print array contents centered in space

            if (column < 3 - 1)                                                    // conditional for printing vertical separators
            {
                cout << '|';
            }

        }

        if (row < 3 - 1)                                                         // conditional for printing horizontal separators
        {
            cout << "\n-----------\n";
        }

        ptr = ptr + 3;                                                             // increment board_ptr to next row of columns
    }
}

void Game::PlayGame()
{
    char input = '\0';

    bool continuePlaying = true;
    bool endGame = false;
    bool fin = false;

    //Game Loop
    while (continuePlaying)
    {
        // draw board
        DisplayBoard();

        // choose space
        while (endGame != true)
        {
            // get input
            cout << "Enter choice of space (1-9) to claim: ";
            cin >> input;

            // check space (token needs converted to classes)
            ClaimSpace(player, input);

            // check game
            fin = GameOver();

            // change player (needs conversion to classes)
            player = (player.GetToken() == 'X') ? 'O' : 'X';
        }
    }

}


}
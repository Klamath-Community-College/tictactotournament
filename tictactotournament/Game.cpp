#include "Game.h"
#include "Player.h"
#include <cctype>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Default ctor, initializes game settings to easy mode
*
******************************************************************************/
Game::Game() : m_Difficulty('E'), m_Countdown(3), m_Tracker(1)
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
Game::Game(char diff, int count, int track) : m_Difficulty('E'), m_Countdown(3), m_Tracker(1)
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
* Entry: int space
*
* Exit: contents of space
*
* Purpose: Sets difficulty value for game
*
******************************************************************************/
char Game::GetSpace(int space) const
{
    int row = (space - 1) / 3;
    int clm = (space - 1) % 3;
    return m_Board[row][clm];
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
* Entry: int space, Player player
*
* Exit: Nothing
*
* Purpose: Sets claim token in chosen space
*
******************************************************************************/
void Game::SetSpace(int space, Player player)
{
    int row = (space - 1) / 3;
    int clm = (space - 1) % 3;
    m_Board[row][clm] = player.GetToken();
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

    for (int space = 1; space <=9; space++)        // use space content not element #
    { 
        // space is comparing int to char, so typecast
        if (GetSpace(space) == static_cast<char>(space) && space > 0 && space <= 9)
        {
            // default contents exist, do nothing
        }
    }
    return draw;  // No elements found matching index + 1
}

/******************************************************************************
* Entry: Nothing
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

    if (GetSpace(0) == GetSpace(1) == GetSpace(2) || GetSpace(3) == GetSpace(4) == GetSpace(5) || GetSpace(6) == GetSpace(7) == GetSpace(8))
    {
        // if win is horizontal
        result = true;
    }
    else if (GetSpace(0) == GetSpace(3) == GetSpace(6) || GetSpace(1) == GetSpace(4) == GetSpace(7) || GetSpace(2) == GetSpace(5) == GetSpace(8))
    {
        // if win is vertical
        result = true;
    }
    else if (GetSpace(0) == GetSpace(4) == GetSpace(8) || GetSpace(2) == GetSpace(4) == GetSpace(6))
    {
        // if win is diagonal
        result = true;
    }
    else if (gameDiff == 'E')
    {
        // if all spaces filled on easy (non-combat)
        //result = TestDraw();
        //cout << "All spaces are filled - game is a draw!";
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
void Game::ClaimSpace(Player playerOn, Player playerOff, char input)
{
    Champion baseChamp;
    char selection = input;
    int tempInput = int(input);

    if (selection >= '1' && selection <= '9')
    {
        switch (selection)
        {
        case '1':
            if (GetSpace(tempInput - 1) == '1')
            {
                SetSpace(tempInput - 1, playerOn);
            }
            else if (GetSpace(tempInput - 1) != playerOn.GetToken())
            {
                // call PVP function

            }
            else
            {
                cout << "You have already claimed this space!";
            }
            break;
        case '2':
            if (GetSpace(tempInput - 1) == '2')
            {
                SetSpace(tempInput - 1, playerOn);
            }
            else if (GetSpace(tempInput - 1) != playerOn.GetToken())
            {
                // call PVP function

            }
            else
            {
                cout << "You have already claimed this space!";
            }
            break;
        case '3':
            if (GetSpace(tempInput - 1) == '3')
            {
                SetSpace(tempInput - 1, playerOn);
            }
            else if (GetSpace(tempInput - 1) != playerOn.GetToken())
            {
                // call PVP function

            }
            else
            {
                cout << "You have already claimed this space!";
            }
            break;
        case '4':
            if (GetSpace(tempInput - 1) == '4')
            {
                SetSpace(tempInput - 1, playerOn);
            }
            else if (GetSpace(tempInput - 1) != playerOn.GetToken())
            {
                // call PVP function

            }
            else
            {
                cout << "You have already claimed this space!";
            }
            break;
        case '5':
            if (GetSpace(tempInput - 1) == '5')
            {
                SetSpace(tempInput - 1, playerOn);
            }
            else if (GetSpace(tempInput - 1) != playerOn.GetToken())
            {
                // call PVP function

            }
            else
            {
                cout << "You have already claimed this space!";
            }
            break;
        case '6':
            if (GetSpace(tempInput - 1) == '6')
            {
                SetSpace(tempInput - 1, playerOn);
            }
            else if (GetSpace(tempInput - 1) != playerOn.GetToken())
            {
                // call PVP function

            }
            else
            {
                cout << "You have already claimed this space!";
            }
            break;
        case '7':
            if (GetSpace(tempInput - 1) == '7')
            {
                SetSpace(tempInput - 1, playerOn);
            }
            else if (GetSpace(tempInput - 1) != playerOn.GetToken())
            {
                // call PVP function

            }
            else
            {
                cout << "You have already claimed this space!";
            }
            break;
        case '8':
            if (GetSpace(tempInput - 1) == '8')
            {
                SetSpace(tempInput - 1, playerOn);
            }
            else if (GetSpace(tempInput - 1) != playerOn.GetToken())
            {
                // call PVP function

            }
            else
            {
                cout << "You have already claimed this space!";
            }
            break;
        case '9':
            if (GetSpace(tempInput - 1) == '9')
            {
                SetSpace(tempInput - 1, playerOn);
            }
            else if (GetSpace(tempInput - 1) != playerOn.GetToken())
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
* Entry: Nothing
*
* Exit: No return
*
* Purpose: Displays current state of game using gameBoard array
*
******************************************************************************/
void Game::DisplayBoard()
{
    // insert blank space
    cout << "\n\n" << endl;
    // display row one and separator
    cout << ' ' << GetSpace(1) << ' ' << '|' << ' ' << GetSpace(2) << ' ' << '|' << ' ' << GetSpace(3);
    cout << "\n-----------\n";
    // display row two and separator
    cout << ' ' << GetSpace(4) << ' ' << '|' << ' ' << GetSpace(5) << ' ' << '|' << ' ' << GetSpace(6);
    cout << "\n-----------\n";
    // display row three
    cout << ' ' << GetSpace(7) << ' ' << '|' << ' ' << GetSpace(8) << ' ' << '|' << ' ' << GetSpace(9) << '\n' << endl;
}

void Game::PlayGame(bool tourney)
{
    char input = '\0';

    bool continuePlaying = true;
    bool endGame = false;
    bool fin = false;
    Player player1;
    Player player2;
    Champion baseChamp;

    //Game Loop
    while (continuePlaying)
    {
        // ask user for difficulty
        cout << "Select difficulty - (E)asy, (N)ormal or (H)ard: ";
        cin >> input;

        // create game, set difficulty
        if (toupper(input) == 'N')
        {
            Game newGame();
            SetDifficulty('N');
            SetCountdown(3);
            if (tourney == true)
            {
                SetTracker(GetTracker() + 1);
            }
            
        }
        else if (toupper(input) == 'H')
        {
            Game newgame();
            SetDifficulty('H');
            SetCountdown(0);
            if (tourney == true)
            {
                SetTracker(GetTracker() + 1);
            }
        }

        //set number of players
        int numPlayers = 0;
        cout << "Enter number of players (1 or 2): ";
        cin >> input;
        numPlayers = input;

        // set player options
        if (numPlayers == 1)
        {
            // player 1
            cout << "Select token for player 1 (X or O): ";
            cin >> input;

            Player player1(true, toupper(input), 0);
            cout << "Select your champion - (W)arrior, (Adept) or (R)ogue: ";
            cin >> input;
            player1.GetChampion().SetRole(toupper(input));

            // player 2 (AI)
            Player player2(false, '\0', 0);
            player1.GetToken() == 'X' ? player2.SetToken('O') : player2.SetToken('X');
            input = baseChamp.GenerateRNG(1, 3);
            if (toupper(input) == 1)
            {
                player2.GetChampion().SetRole('W');
            }
            else if (toupper(input) == 2)
            {
                player2.GetChampion().SetRole('A');
            }
            else
            {
                player2.GetChampion().SetRole('R');
            }

        }
        else
        {
            // player 1
            cout << "Select token for player 1 (X or O): ";
            cin >> input;

            Player player1(true, toupper(input), 0);
            cout << "Select your champion - (W)arrior, (Adept) or (R)ogue: ";
            cin >> input;
            player1.GetChampion().SetRole(toupper(input));

            // player 2
            Player player2(true, '\0', 0);
            player1.GetToken() == 'X' ? player2.SetToken('O') : player2.SetToken('X');
            cout << "Select your champion - (W)arrior, (Adept) or (R)ogue: ";
            cin >> input;
            player2.GetChampion().SetRole(toupper(input));
        }

        // draw board
        DisplayBoard();

        // choose space
        while (endGame != true)
        {
            // get input for player 1
            cout << "Enter choice of space (1-9) for player 1: ";
            cin >> input;

            // check space
            ClaimSpace(player1, player2, input);

            // draw board
            DisplayBoard();

            // check game
            fin = GameOver();

            // get input for player 2
            cout << "Enter choice of space (1-9) for player 2: ";
            cin >> input;

            // check space
            ClaimSpace(player2, player1, input);

            // draw board
            DisplayBoard();

            // check game
            fin = GameOver();
        }
    }
}
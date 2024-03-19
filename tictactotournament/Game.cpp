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
    Player player1(true, 'X', 0);
    Player player2(true, 'O', 0);
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
    Player player1(true, 'X', 0);
    Player player2(true, 'O', 0);
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
* Exit: m_Board[][] contents
*
* Purpose: Returns contents of selected space
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
        if (GetSpace(space) == static_cast<char>(space))
        {
            // default content exists, do nothing
        }
        else
        {
            // test for player tokens in all spaces
            GetSpace(space) == 'X' || GetSpace(space) == 'O' && space == 9 ? draw = true : draw = false;
        }
    }
    return draw;
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

    // if win is horizontal
    if (GetSpace(0) == GetSpace(1) == GetSpace(2) || GetSpace(3) == GetSpace(4) == GetSpace(5) || GetSpace(6) == GetSpace(7) == GetSpace(8))
    {
        result = true;
    }
    // if win is vertical
    else if (GetSpace(0) == GetSpace(3) == GetSpace(6) || GetSpace(1) == GetSpace(4) == GetSpace(7) || GetSpace(2) == GetSpace(5) == GetSpace(8))
    {
        result = true;
    }
    // if win is diagonal
    else if (GetSpace(0) == GetSpace(4) == GetSpace(8) || GetSpace(2) == GetSpace(4) == GetSpace(6))
    {  
        result = true;
    }
    //else if (gameDiff == 'E')
    //{
    //    // if all spaces filled on easy (non-combat)
    //    if (TestDraw() == true)
    //    {
    //        cout << "All spaces are filled - game is a draw!";
    //    }
    //    result = true;
    //}
    //else if (gameDiff != 'E')
    //{
    //    // if all spaces filled not on easy (non-combat)
    //    cout << "All spaces are filled - only victory by combat remains!";
    //} 
    else
    {
        cout << "Spaces remain, next player goes. ";
    }



    return result;
}


/******************************************************************************
* Entry: Player playerOn (the active player - challenger)
*        Player playerOff (the inactive player - defender)
*        char input (space chosen)
*
* Exit: no return
*
* Purpose: Compares player choice to board and performs correct actions
*
******************************************************************************/
void Game::ClaimSpace(Player playerOn, Player playerOff, char input)
{
    if (input >= '1' && input <= '9')
    {
        switch (input)
        {
        case '1':
            if (GetSpace(1) == '1')                                                                // compare to default value
            {
                SetSpace(1, playerOn);                                                            // set to player token
            }
            else if (GetDifficulty() != 'E' && GetSpace(1) == playerOff.GetToken())               // compare to opponent's token
            {
                playerOn.ChallengeSpace(playerOn, playerOff, input);                              // call PVP function

            }
            else if (GetSpace(1) == playerOn.GetToken())                                           // if space selected by current player
            {
                cout << "You have already claimed this space!";
            }
            else
            {
                cout << "You cannot claim this space.";
            }
            break;
        case '2':
            if (GetSpace(2) == '2')
            {
                SetSpace(2, playerOn);
            }
            else if (GetDifficulty() != 'E' && GetSpace(2) == playerOff.GetToken())               // compare to opponent's token
            {
                playerOn.ChallengeSpace(playerOn, playerOff, input);

            }
            else if (GetSpace(2) == playerOn.GetToken())                // if space selected but not by opponent
            {
                cout << "You have already claimed this space!";
            }
            else
            {
                cout << "You cannot claim this space.";
            }
            break;
        case '3':
            if (GetSpace(3) == '3')
            {
                SetSpace(3, playerOn);
            }
            else if (GetDifficulty() != 'E' && GetSpace(3) == playerOff.GetToken())               // compare to opponent's token
            {
                playerOn.ChallengeSpace(playerOn, playerOff, input);

            }
            else if (GetSpace(3) == playerOn.GetToken())                // if space selected but not by opponent
            {
                cout << "You have already claimed this space!";
            }
            else
            {
                cout << "You cannot claim this space.";
            }
            break;
        case '4':
            if (GetSpace(4) == '4')
            {
                SetSpace(4, playerOn);
            }
            else if (GetDifficulty() != 'E' && GetSpace(4) == playerOff.GetToken())               // compare to opponent's token
            {
                playerOn.ChallengeSpace(playerOn, playerOff, input);

            }
            else if (GetSpace(4) == playerOn.GetToken())                // if space selected but not by opponent
            {
                cout << "You have already claimed this space!";
            }
            else
            {
                cout << "You cannot claim this space.";
            }
            break;
        case '5':
            if (GetSpace(5) == '5')
            {
                SetSpace(5, playerOn);
            }
            else if (GetDifficulty() != 'E' && GetSpace(5) == playerOff.GetToken())               // compare to opponent's token
            {
                playerOn.ChallengeSpace(playerOn, playerOff, input);

            }
            else if (GetSpace(5) == playerOn.GetToken())                // if space selected but not by opponent
            {
                cout << "You have already claimed this space!";
            }
            else
            {
                cout << "You cannot claim this space.";
            }
            break;
        case '6':
            if (GetSpace(6) == '6')
            {
                SetSpace(6, playerOn);
            }
            else if (GetDifficulty() != 'E' && GetSpace(6) == playerOff.GetToken())               // compare to opponent's token
            {
                playerOn.ChallengeSpace(playerOn, playerOff, input);

            }
            else if (GetSpace(6) == playerOn.GetToken())                // if space selected but not by opponent
            {
                cout << "You have already claimed this space!";
            }
            else
            {
                cout << "You cannot claim this space.";
            }
            break;
        case '7':
            if (GetSpace(7) == '7')
            {
                SetSpace(7, playerOn);
            }
            else if (GetDifficulty() != 'E' && GetSpace(7) == playerOff.GetToken())               // compare to opponent's token
            {
                playerOn.ChallengeSpace(playerOn, playerOff, input);

            }
            else if (GetSpace(7) == playerOn.GetToken())                // if space selected but not by opponent
            {
                cout << "You have already claimed this space!";
            }
            else
            {
                cout << "You cannot claim this space.";
            }
            break;
        case '8':
            if (GetSpace(8) == '8')
            {
                SetSpace(8, playerOn);
            }
            else if (GetDifficulty() != 'E' && GetSpace(8) == playerOff.GetToken())               // compare to opponent's token
            {
                playerOn.ChallengeSpace(playerOn, playerOff, input);

            }
            else if (GetSpace(8) == playerOn.GetToken())                // if space selected but not by opponent
            {
                cout << "You have already claimed this space!";
            }
            else
            {
                cout << "You cannot claim this space.";
            }
            break;
        case '9':
            if (GetSpace(9) == '9')
            {
                SetSpace(9, playerOn);
            }
            else if (GetDifficulty() != 'E' && GetSpace(9) == playerOff.GetToken())               // compare to opponent's token
            {
                playerOn.ChallengeSpace(playerOn, playerOff, input);

            }
            else if (GetSpace(9) == playerOn.GetToken())                // if space selected but not by opponent
            {
                cout << "You have already claimed this space!";
            }
            else
            {
                cout << "You cannot claim this space.";
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
    Game newGame;
    bool endGame = false;

    //Game Loop
    while (!endGame)
    {
        // set game options
        SetOptions(newGame, tourney);

        // draw board
        newGame.DisplayBoard();

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
            endGame = GameOver();

            // get input for player 2
            cout << "Enter choice of space (1-9) for player 2: ";
            cin >> input;

            // check space
            ClaimSpace(player2, player1, input);

            // draw board
            DisplayBoard();

            // check game
            endGame = GameOver();
        }
    }
}


void Game::SetOptions(Game game, bool tourney)
{
    char input = '\0';

    // ask user for difficulty
    cout << "Select difficulty - (E)asy, (N)ormal or (H)ard: ";
    cin >> input;

    // create game, set difficulty
    if (input == 'N' || input == 'n')
    {
        game.SetDifficulty('N');
        game.SetCountdown(3);
        game.SetTracker(1);
        if (tourney == true)
        {
            SetTracker(GetTracker() + 1);
        }

    }
    else if (input == 'H' || input == 'h')
    {
        game.SetDifficulty('H');
        game.SetCountdown(0);
        game.SetTracker(1);
        if (tourney == true)
        {
            SetTracker(GetTracker() + 1);
        }
    }

    //set number of players
    cout << "Enter number of players (1 or 2): ";
    cin >> input;

    // set player options
    if (input == '1')
    {
        // player 1 Champion
        cout << "Select your champion for player 1 - (W)arrior, (Adept) or (R)ogue: ";
        cin >> input;
        input = toupper(input);
        player1.GetChampion().SetRole(input);

        // player 2 (AI) Champion
        int AI_Role = player2.GetChampion().GenerateRNG(1, 3);
        if (AI_Role == 1)
        {
            player2.GetChampion().SetRole('W');
            cout << "Computer has chosen Warrior." << endl;
        }
        else if (AI_Role == 2)
        {
            player2.GetChampion().SetRole('A');
            cout << "Computer has chosen Adept." << endl;
        }
        else
        {
            player2.GetChampion().SetRole('R');
            cout << "Computer has chosen Rogue." << endl;
        }

    }
    else if (input == '2')
    {
        // player 1 Champion
        cout << "Select your champion for player 1 - (W)arrior, (Adept) or (R)ogue: ";
        cin >> input;
        input = toupper(input);
        player1.GetChampion().SetRole(input);

        // player 2 Champion
        cout << "\nSelect your champion for player 2 - (W)arrior, (Adept) or (R)ogue: ";
        cin >> input;
        input = toupper(input);
        player2.GetChampion().SetRole(input);
    }
}
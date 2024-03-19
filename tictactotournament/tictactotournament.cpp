#define _CRTDBG_MAP_ALLOC
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Place any other #includes here
#include "Game.h"
#include "Player.h"
#include "Champion.h"
#include "Node.h"
#include "HighScore.h"
#include "LinkedList.h"

#include <crtdbg.h>

void DisplayMenu_Main();
void DisplayMenu_Inst();
void DisplayInst_Basic();
void DisplayInst_New();
void DisplayMenu_Scores();
char GetInput();

int main()
{
    // Run this program using "Start Debugging"
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


    bool exit = false;
    char input = '\0';
    Game gameAccess;
    bool tourney = false;
    LinkedList playerScores;
    // figure out where to put function for recording score
    //
    //      HighScore* winnerScore = new HighScore(input, wins, champion);
    //      playerScores.InsertOrdered(winnerScore);
    //

    while (!exit)
    {
        DisplayMenu_Main();
        input = GetInput();

        if (input >= '1' && input <= '5')
        {
            switch (input)
            {
            case '1':
                gameAccess.PlayGame(tourney);
                break;
            case '2':
                tourney = true;
                gameAccess.PlayGame(tourney);
                break;
            case '3':
                DisplayMenu_Scores();
                break;
            case '4':
                DisplayMenu_Inst();
                break;
            case '5':
                exit = true;
                break;
            }
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }
}

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Displays main menu
*
******************************************************************************/
void DisplayMenu_Main()
{
    cout << "\n\n" << "TIC TAC TOURNAMENT" << endl;
    cout << "\nMain Menu" << "\n---------" << endl;
    cout << "1) New Game\n" <<
        "2) Continue Playing\n" <<
        "3) High Scores\n" <<
        "4) Instructions\n" <<
        "5) Exit\n" << endl;
    cout << "Selection: ";
}

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Displays Instruction menu
*
******************************************************************************/
void DisplayMenu_Inst()
{
    cout << "\n\nInstruction Menu" << "\n---------" << endl;
    cout << "1) How to Play\n" <<
        "2) New Feature - Combat\n" <<
        "3) Back to Main Menu\n" << endl;
    cout << "Selection: ";

    char input = GetInput();

    if (input != '3')
    {
        if (input == '1')
        {
            DisplayInst_Basic();
        }
        else if (input == '2')
        {
            DisplayInst_New();
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }
}

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Displays Instructions for basic Tic Tac Toe
*
******************************************************************************/
void DisplayInst_Basic()
{
    cout << "\n\n\t\tRules of Tic Tac Toe" << endl;
    cout << "\nThe rules of Tic Tac Toe are as follows:"
        << "\n\tA player can put only a single letter X or O in the 3 x 3 grid in each chance."
        << "\n\tBoth players will get chances alternatively one after another till someone wins or draws."
        << "\n\tTo win this game, the player must create a horizontal, vertical, or diagonal line consisting of three same letters."
        << "\n\tThe game is drawn, if all grids are filled with X or O letters but no line is made."
        << "\n\nThis is the basic game and what will be played on the Easy setting, for other difficulties see the New Features menu."
        << endl;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Displays Instructions for New Feature (Combat)
*
******************************************************************************/
void DisplayInst_New()
{
    cout << "\n\n\t\tRules of Tic Tac Tournament" << endl;
    cout << "\nThe rules of Tic Tac Tournament change as follows:"
        << "\n\tEach player will choose a champion to serve as their avatar in the game."
        << "\n\tClaimed squares may be contested at point based on difficulty selected."
        << "\n\t\tEasy - no combat \n\t\tNormal - combat can begin after # turns \n\t\tHard - Combat can start immediately" << endl;

    // describe champions, bonuses
    cout << "\n\nEach champion has four varying scores - Power, Mental, Agility and Health. The different champions benefit from these "
        << "scores in different ways: \n\tThe Warrior relies on Power and gains this bonus to damage on a successful attack."
        << "\n\tThe Adept relies on Mental and gains this bonus to attack against an opponent's Agility."
        << "\n\tThe Rogue relies on Agility and applies this bonus twice when deciding the target number his opponent must hit."
        << endl;
}

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Displays Scores menu
*
******************************************************************************/
void DisplayMenu_Scores()
{
    cout << "\n\n High Scores Menu" << "\n---------" << endl;
    cout << "1) Player wins\n" <<
        "2) Avatar wins\n" <<
        "3) Back to Main Menu\n" << endl;
    cout << "Selection: ";

    char input = GetInput();

    if (input != '3')
    {
        if (input == '1')
        {
            // file i/o for player wins
            cout << "Player wins will display after feature developed." << endl;
        }
        else if (input == '2')
        {
            // file i/o for avatar wins
            cout << "Champion wins will display after feature developed." << endl;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }
}

char GetInput()
{
    char temp_input = '\0';
    cin >> temp_input;
    return temp_input;
}
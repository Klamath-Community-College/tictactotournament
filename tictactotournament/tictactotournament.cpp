#define _CRTDBG_MAP_ALLOC
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Place any other #includes here
//#include "Game.h"
//#include "Player.h"
//#include "Champion.h"

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

    /**********************************************************************************
    * Game Logic
    *
    *   Splash screen?
    *   Main Menu
    *       1. Play
    *           1. New Game
    *               class Player
    *                   -> token, avatar, #wins, AI, name?
    *               class game/board
    *                   -> board, Difficulty, counter, player1, player2
    *           2. Continue Playing
    *                   -> link list for consecutive games?
    *           3. Back
    *       2. Instructions
    *           1. How to Play
    *                   Easy (non-combat), Normal (combat w/counter), Hard (immediate combat)
    *           2. New Feature (combat)
    *                   -> stats array, class differential, #wins
    *                   -> AI as unique?
    *           3. Back
    *       3. High Scores
    *           1. Player (#wins)
    *           2. Avatar (#wins/level?)
    *           3. Back
    *       4. Exit
    *
    *
    * Combat Logic
    *       Combat(int attacker, int defender, int space)       // change int to Player?
    *       {
    *           while (attacker.health != 0 || defender.health != 0)
    *           {
    *               attacker.att (rng+stat) > defender.def (stat) ? def.health -= damage : def.health -= 0
    *               defender.att (rng+stat) > attacker.def (stat) ? att.health -= damage : att.health -= 0
    *           }
    *
    *           if (attacker.health != 0)
    *           {
    *               space = attacker.token
    *               cout << "The attacker has won and space is claimed!" << endl;
    *           }
    *           else
    *           {
    *               cout << "The defender has won and space is kept!" << endl;
    *           }
    *
    ***********************************************************************************/

    bool exit = false;
    char input = '\0';

    while (!exit)
    {
        DisplayMenu_Main();
        input = GetInput();

        if (input >= '1' && input <= '5')
        {
            switch (input)
            {
            case '1':

                break;
            case '2':

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

    while (input != '3')
    {
        if (input == '1')
        {
            // file i/o for player wins
            cout << "Player wins will display after games have been played." << endl;
        }
        else if (input == '2')
        {
            // file i/o for avatar wins
            cout << "Champion wins will display after games have been played." << endl;
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
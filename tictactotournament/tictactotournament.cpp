#define _CRTDBG_MAP_ALLOC
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Place any other #includes here
#include "Game.h"
#include "Player.h"

#include <crtdbg.h>


const int BOARD = 3;
void DisplayBoard(char* ptr);
bool GameOver(char* ptr, char difficulty);
void ClaimSpace(char token, char input, char * ptr);
void DisplayMenu_Main();
void DisplayMenu_Inst();
void DisplayInst_Basic();
void DisplayInst_New();
void DisplayMenu_Scores();

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
    * Required Variables
    * 
    *   ENUM Menu
    *   int countdown (for diff/combat)
    *   int spaceSelection (for input)
    *   char abcInput[3] (for score inits)
    *      
    ***********************************************************************************/

    // Create board array
    char board[BOARD][BOARD] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

    // Assign pointer to board[]
    char * board_ptr = board[0];

    char input = '\0';
   
    bool continuePlaying = true;
    bool endGame = false;
    bool fin = false;



    
    GameOver(board_ptr, difficulty);
    ClaimSpace(tokenX, input, board_ptr);
    DisplayMenu_Main();
    
    //Game Loop
    while (continuePlaying)
    {
        // draw board
        DisplayBoard(board_ptr);

        // choose space
        while (endGame != true)
        {
            // get input
            cout << "Enter choice of space (1-9) to claim: ";
            cin >> input;

            // check space (token needs converted to classes)
            ClaimSpace(token, input, board_ptr);

            // check game
            fin = GameOver(board_ptr, difficulty);

            // change player (needs conversion to classes)
            player = (player == 'X') ? 'O' : 'X';
        }
    }

    return 0;
}


/******************************************************************************
* Entry: Pointer to gameBoard array (board_ptr)
*
* Exit: No return
*
* Purpose: Displays current state of game using gameBoard array
*
******************************************************************************/
void DisplayBoard(char* ptr)
{
    for (int row = 0; row < BOARD; row++)                                            // loop for displaying rows
    {
        for (int column = 0; column < BOARD; column++)                               // loop for displaying columns
        {
            cout << ' ' << *(ptr + column) << ' ';                                 // print array contents centered in space
            
            if (column < BOARD-1)                                                    // conditional for printing vertical separators
            {
                cout << '|';
            }

        }

        if (row < BOARD - 1)                                                         // conditional for printing horizontal separators
        {
            cout << "\n-----------\n";
        }
        
        ptr = ptr+BOARD;                                                             // increment board_ptr to next row of columns
    }
}

/******************************************************************************
* Entry: Pointer to gameBoard array (board_ptr), char difficulty
*
* Exit: Bool result
*
* Purpose: Computes if game has been won
*
******************************************************************************/
bool GameOver(char* ptr, char difficulty)
{
    bool result = false;

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
    else if (ptr[0] == 'x' || 'o' && ptr[1] == 'x' || 'o' && ptr[2] == 'x' || 'o' && ptr[3] == 'x' || 'o' && ptr[4] == 'x' || 'o' &&
        ptr[5] == 'x' || 'o' && ptr[6] == 'x' || 'o' && ptr[7] == 'x' || 'o' && ptr[8] == 'x' || 'o' && difficulty == 'E')
    {
        // if all spaces filled on easy (non-combat)
        result = true;
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
void ClaimSpace(char token, char input, char * ptr)
{
    if (input >= '1' && input <= '9')
    {
        switch (input)
        {
            case '1':
                if (ptr[input - 1] == '1')
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
    cout << "1) Play Game\n" <<
        "2) High Scores\n" <<
        "3) Instructions\n" <<
        "4) Exit\n" << endl;
    cout << "Selection: ";
}

/******************************************************************************
* Entry: Nothing
*
* Exit: Nothing
*
* Purpose: Displays play menu
*
******************************************************************************/
void DisplayMenu_Play()
{
    cout << "\n\nPlay Menu" << "\n---------" << endl;
    cout << "1) New Game\n" <<
        "2) Continue Playing\n" <<
        "3) Back to Main Menu\n" << endl;
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
#define _CRTDBG_MAP_ALLOC
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Place any other #includes here

#include <crtdbg.h>

// Set board size
const int ROW = 3;
const int CLM = 3;

void DisplayBoard(char* ptr);
bool GameOver(char* ptr);
void ClaimSpace(char token, char input, char * ptr);
void DisplayMenu_Main();

int main()
{
    // Run this program using "Start Debugging"
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // Create board[ROW][CLM] array
    char board[ROW][CLM] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };

    // Assign pointer to board[]
    char * board_ptr = board[0];

    char tokenX = 'X';
    char tokenO = 'O';
    char input = '\0';

    DisplayBoard(board_ptr);
    GameOver(board_ptr);
    ClaimSpace(tokenX, input, board_ptr);
    DisplayMenu_Main();

    return 0;
}

/******************************************************************************
* Entry: <what is passed in>
*
* Exit: <what is returned>
*
* Purpose: <description of function>
*
*
******************************************************************************/

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
    for (int row = 0; row < ROW; row++)                                            // loop for displaying rows
    {
        for (int column = 0; column < CLM; column++)                               // loop for displaying columns
        {
            cout << ' ' << *(ptr + column) << ' ';                                 // print array contents centered in space
            
            if (column < CLM-1)                                                    // conditional for printing vertical separators
            {
                cout << '|';
            }

        }

        if (row < ROW - 1)                                                         // conditional for printing horizontal separators
        {
            cout << "\n-----------\n";
        }
        
        ptr = ptr+ROW;                                                             // increment board_ptr to next row of columns
    }
}

/******************************************************************************
* Entry: Pointer to gameBoard array (board_ptr)
*
* Exit: Bool result
*
* Purpose: Computes if game has been won
*
******************************************************************************/
bool GameOver(char* ptr)
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
    cout << "1) New Game\n" <<
        "2) High Scores\n" <<
        "3) Instructions\n" <<
        "4) Exit\n" << endl;
    cout << "Selection: ";
}
#define _CRTDBG_MAP_ALLOC
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

// Place any other #includes here

#include <crtdbg.h>

const int ROW = 3;
const int CLM = 3;

void DisplayBoard(char* ptr);


int main()
{
    // Run this program using "Start Debugging"
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    // Create board[ROW][CLM] array
    char board[ROW][CLM] = { {'0', '1', '2'}, {'3', '4', '5'}, {'6', '7', '8'} };

    // Assign pointer to board[]
    char * board_ptr = board[0];

    DisplayBoard(board_ptr);

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
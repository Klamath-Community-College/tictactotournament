#define _CRTDBG_MAP_ALLOC 
// Place any other #includes here

#include <crtdbg.h>

int main()
{
    // Run this program using "Start Debugging"
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    int* ptr = new int;

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
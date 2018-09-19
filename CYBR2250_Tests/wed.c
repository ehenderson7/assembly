/* ============================================================

Example program for Wednesday!

Author:  Bill Mahoney
For:     CYBR 2250, Fall 2017

============================================================ */

#include <stdio.h>

/* ============================================================
Remember, you have to prototype the function, especially if it is not
defined in this file.
============================================================ */
void far_away_function( void ); // Not just ()

/* ============================================================
This is a variable that will be accessible everywhere.
============================================================ */
int global_variable;

/* ============================================================
Start here
============================================================ */
int main()
{
    scanf( "%d", &global_variable );
    printf( "You entered %d (0x%x), let's call the far away function.\n", global_variable, global_variable );
    far_away_function();
    printf( "The result is %d (0x%x)!!!\n", global_variable, global_variable );
    return( 0 );
}

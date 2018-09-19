// ======================================================================
//
// Monotone numbers
//
// From a math puzzle in the Wall Street Journal, some time in August 2017.
//
// "Call a number monotonous if its digits are in strictly ascending
// order, left to right. So for example 359 is monotonous, but neither
// 2446 nor 2480 is. The samllest 5-digit monotonous number is
// 12345. What is the 100th smallest 5-digit monotonous number?"
//
// Author:   Bill
// For:      CYBR 2250
//
// ======================================================================

#include <stdio.h>
#include <string.h>

const int true  = 1;
const int false = 0;

// Scan the string front to back looking for mistakes.

int mono( const char *str )
{
    while ( *( str + 1 ) )
        if ( *str >= *( str + 1 ) )
            return( false );
        else
            str++;
    return( true );
}

// Crate all 5-digit strings, test them one at a time.

int main()
{
    char     test[ 6 ];
    unsigned count = 1;

    test[ 5 ] = '\0';

    // The description says that the smallest is 12345, so although
    // they do not say it, leading zeros must not be allowed.
    // Thus the first loop starts at 1. 

    // Also, we could limit this here instead of above, by making the
    // test[1] loop go from test[0]+1 through '9', but what we want to show
    // is the pointers being passed to the function, so although this is not
    // a good way to do it this is how it is set up here.

    for( test[ 0 ] = '1'; test[ 0 ] <= '9'; test[ 0 ]++ )
        for( test[ 1 ] = '0'; test[ 1 ] <= '9'; test[ 1 ]++ )
            for( test[ 2 ] = '0'; test[ 2 ] <= '9'; test[ 2 ]++ )
                for( test[ 3 ] = '0'; test[ 3 ] <= '9'; test[ 3 ]++ )
                    for( test[ 4 ] = '0'; test[ 4 ] <= '9'; test[ 4 ]++ )
                        if ( mono( test ) )
                            printf( "%5u %s\n", count++, test );
    return( 0 );
}

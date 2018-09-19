// ============================================================
//
// Just a little demo program to show how to link things together with
// assembly.
//
// Usage: ./andor number operation number
// Where "operation" is AND, OR, XOR
//
// Author: Bill
// For:    CYBR 2250
//
// ============================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int usage( char * );
unsigned work( unsigned l, char op, unsigned r );

int main( int ac, char *av[] )
{

    if ( ac != 4 )
        return( usage( av[ 0 ] ) );
    if ( ( strcmp( av[ 2 ], "AND" ) != 0 ) &&
         ( strcmp( av[ 2 ], "OR" ) != 0 ) &&
         ( strcmp( av[ 2 ], "XOR" ) != 0 ) )
        return( usage( av[ 0 ] ) );

    // Otherwise call the function
    unsigned left  = strtoul( av[ 1 ], NULL, 16 );
    unsigned right = strtoul( av[ 3 ], NULL, 16 );
    printf( "0x%x %s 0x%x = 0x%x\n",
            left, av[ 2 ], right,
            work( left, av[ 2 ][ 0 ], right ) );

    return( 0 );
}

int usage( char *prog )
{
    printf( "%s: You need to supply NUMBER OP NUMBER\n"
            "Where OP is one of \"AND\" \"OR\" or \"XOR\"\n"
            "Also, NUMBER is assumed to be in hex.\n",
            prog );
    return( 1 );
}

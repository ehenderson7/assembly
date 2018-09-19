// ============================================================
//
// Demonstrate passing an array into some assembler.
//
// Author: Bill
// For:    CYBR 2250
//
// ============================================================

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int has42( unsigned *l, int n );

int main( int ac, char *av[] )
{
    unsigned a[] = { 1, 3, 5, 2, 4, 6 };
    if ( has42( a, sizeof( a ) / sizeof( a[ 0 ] ) ) )
        printf( "Array a has a 42!\n" );
    else
        printf( "Array a is boring\n" );

    unsigned b[] = { 56, 34, 12, 90, 42, 67, 56, 45, 34, 23, 12 };
    if ( has42( b, sizeof( b ) / sizeof( b[ 0 ] ) ) )
        printf( "Array b has a 42!\n" );
    else
        printf( "Array b is boring\n" );

    unsigned c[] = { 123, 234, 345, 456, 567, 678, 789, 890, 901, 42 };
    if ( has42( c, sizeof( c ) / sizeof( c[ 0 ] ) ) )
        printf( "Array c has a 42! Let's hear it for array c!!!\n" );
    else
        printf( "Array c is boring\n" );

    return( 0 );
}

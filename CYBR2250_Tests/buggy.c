/* ============================================================

buggy.c

This program is for demo-ing the debugger.  Naturally it has some bugs
that we wish to find. The purpose of the program is to sort a bunch of
integers which are read from the terminal.  The program reads all
integers until end-of-file, then sorts the integers, then prints them
out.  We'll use a selection sort for the actual sorting.  It is way too
inefficient for a "real" program, but is simple.

Now, to save some time I can tell you where the bugs are. Or give you
a hint. One is on line 33, the next is on line 34, and the third is at
line 35. But that's all I am going to say.

Author:     Bill Mahoney
For:        CSCI1840. Oh wait, CSCI2240. Oh! Wait! CYBR2250.

=============================================================== */

#include <stdio.h>
#define  MAX_ARRAY  10

void select_sort( int *, int );

int main( int ac, char *av[] )
{
    int     count, output_loop;
    int     sort_array[ MAX_ARRAY ];

    count = 1;
    printf( "Enter the first number? " );
    while ( scanf( "%d", &sort_array[ count++ ] ) == 1 )
        printf( "Read %d ok, what next? ", sort_array[ count - 1 ] );
    select_sort( sort_array, count );
    for( output_loop = 0; output_loop < count; output_loop++ )
        printf( "%d ", sort_array[ output_loop ] );
    printf( "\nThe end!\n" );
    return( 0 );
}

/* ============================================================

select_sort

This is a void function which takes two parameters; one is an array of
integers.  The array is returned sorted in ascending order.

Inputs:     The array, the length of the array
Outputs:    The array, which is sorted now
Returns:    Nothing

============================================================ */

void select_sort( int vec[], int len )
{
    int     pivot, the_rest;

    for( pivot = 0; pivot < len; pivot++ )
        for( the_rest = pivot + 1; the_rest < len; the_rest++ )
            if ( vec[ pivot ] > vec[ the_rest ] )
            {
                // Interchange ("swap") the value at "pivot" and
                // the value at "the_rest".  They are out of order.
                int     swap;
                swap = vec[ pivot ];
                vec[ pivot ] = vec[ the_rest ];
                vec[ the_rest ] = swap;
            }
}



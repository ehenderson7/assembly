// ============================================================
//
// memcpy tester 
//
// ============================================================

#include <stdio.h>

#define  MAX  13

// The real memcpy prototype is in string.h
void *my_memcpy( void *dest, void *source, size_t n );

int main()
{
    int dest[ MAX ];
    int source[ MAX ] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10, 77, 88, 99 };
    int *check, i;

    check = my_memcpy( dest, source, MAX * sizeof( source[ 0 ] ) );
    if ( check != dest )
        printf( "Ooops, it returned the wrong thing!\n" );
    else
        for( i = 0; i < MAX; i++ )
            if ( dest[ i ] != source[ i ] )
                printf( "Oops! Destination %d is not the same as source %d!\n", i, i );
    return( 0 );

}

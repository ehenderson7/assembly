// Here is my Monday program

#include <stdio.h>
#include "./myfile.h"



int double_it( int apples );

int main()
{
    int i = 1;

    while ( i > 0 )
    {
        scanf( "%d", &i );
        printf( "You entered %d hex 0x%x\n", i, i );
        printf( "Double that and you get 0x%x\n", double_it( i ) );
        printf( "Greater than 100 is %d\n", i > 100 );
        switch( i )
        {
            case 4: 
                printf( "four!\n" );
                break;
            default:
                printf( "Something that is not four!\n" );
                break;
        }
    }

    for( int j = 0; j < 3; j++ )
        printf( "%d ", j );
    putchar( '\n' );

    i = -1;
    do {
        printf( "I am in a do loop! Whoot!\nEnter another number: " );
        scanf( "%d", &i );
    } while ( i < 0 );

    if ( i == 4 )
    {
        int another_thing = i;
        printf( "Oh! you neded that with a four!\n" );
        another_thing++;
    }

    // Last but not least
    this_is_a_global = 56;

    return( 0 );
}

int double_it( int x )
{
    return( x * 2 );
}

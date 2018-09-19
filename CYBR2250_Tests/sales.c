/* ===========================================================

sales.c

Sales persons get different commissions. Given a sales amount,
calculate the right extra pay. Again, just a demo program to show some
C code. Not really too sophisticated.

Author:  Bill Mahoney
Date:    today (put a real date here)

=========================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function prototypes. 
// By the way, you can just say "unsigned" and it will assume "int".

unsigned int commission( unsigned int dollars );
void print_dollars( unsigned int amount );

// Normally YOU would put some nice comments here.

int main()
{
    unsigned int sale_amount, comm;

    srand( time( NULL ) );
    printf( "Enter the sales amount: " );
    scanf( "%u", &sale_amount ); // Not %d
    comm = commission( sale_amount );
    printf( "Your commission is " );
    print_dollars( comm );
    return( 0 );
}

// Normally YOU would put some nice comments here as well.

unsigned int commission( unsigned int bucks )
{
    unsigned int c, xtra;

    if ( bucks < 100 )
        c = bucks * 5 / 100;
    else if ( bucks < 1000 )
        c = bucks * 8 / 100;
    else if ( bucks < 10000 )
        c = bucks * 12 / 100;
    else
        c = bucks * 50 / 100;
    xtra = rand() % 10;
    printf( "You got an extra $%d for being nice\n", xtra );
    return( c + xtra );
}

// Normally YOU would put some nice comments here just like above.

void print_dollars( unsigned int amount )
{
    unsigned int   power = 1000000;
    unsigned short stars = 1;

    printf( "$" );
    while ( power )
    {
        if ( amount / power > 0 )
        {
            stars = 0;
            printf( "%u", amount / power );
        }
        else 
            if ( stars )
                printf( "*" );
            else
                printf( "0" );
        if ( power == 1000 || power == 1000000 )
            printf( "," );
        amount -= (amount/power) * power;
        power /= 10;
    }
    printf( "\n" );
}

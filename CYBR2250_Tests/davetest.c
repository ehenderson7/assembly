#include <stdio.h>
int dave( int *, int * );
int main()
{
    int a, b;
    scanf( "%d", &a );
    scanf( "%d", &b );
    printf( "The total is %d\n", dave( &a, &b ) );
    return( 0 );
}

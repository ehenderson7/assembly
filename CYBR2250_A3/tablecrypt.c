/* ============================================================

   Starting point program for the Tablecrypt machine as described in the
   assignment.

Author:  Bill Mahoney
For:     CYBR 2250, Fall 2017
Note:    Removed the debugging.

============================================================ */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void rotate( char t[][ 4 ] );
int encrypt( int ch, char table[][ 4 ] );

// Removed:
// void print_table( char t[][ 4 ] );

int main( int ac, char *av[] )
{
    char table[ 4 ][ 4 ];

    // First line has the table settings.
    for( int i = 0; i < 4; i++ )
        for( int j = 0; j < 4; j++ )
        {
            table[ i ][ j ] = getchar();
            putchar( table[ i ][ j ] );
            if ( ( table[ i ][ j ] != 'S' ) &&
                    ( table[ i ][ j ] != 'N' ) )
            {
                if ( table[ i ][ j ] == '\n' )
                    fprintf( stderr, "%s: There's not enough table settings!\n", av[ 0 ] );
                else
                    fprintf( stderr, "%s: bad table setting: %c\n", av[ 0 ], table[ i ][ j ] );
                return( 1 );
            }
        }

    // Newline
    if ( getchar() != '\n' ) 
    {
        fprintf( stderr, "%s: The table settings are too long!\n", av[ 0 ] );
        return( 2 );
    }

    putchar( '\n' );

    // Encrypt characters
    int ch;
    while ( ( ch = getchar() ) != EOF )
    {
        putchar( encrypt( ch, table ) );    
        rotate( table );
    }
    return( 0 );
}

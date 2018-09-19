// ======================================================================
//
// memcpy-like function
//
// ======================================================================

#include <stdio.h> // for size_t

void *my_memcpy( void *dest, void *src, size_t n )
{
    void *save = dest;
    while ( n-- )
        *((char *) dest++) = *((char *) src++);
    return( save );
}

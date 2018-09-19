#include<stdio.h>

int main() {
    int a[6] = {1,2,3,4,5,6};
    int *p = &a[0];

    printf("*p = %d\n", *p);
    p++;
    printf("++*p = %d\n", ++*p);
    printf("*++p = %d\n", *++p);

    return (0);
    
}

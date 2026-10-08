#include <stdio.h>
#include "myFunctions.h"

int main(void) {

    unsigned int d = 0xAABBCCDD;
    unsigned int *ptr_d = NULL;
    ptr_d = &d;
    int result = sum_integer_bytes(ptr_d);
    
    printf("Sum of integer bytes: %d\n", result);

    return 0;
}
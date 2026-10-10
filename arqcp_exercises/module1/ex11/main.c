#include <stdio.h>
#include "myFunctions.h"

int main() {

    int vec[] = {9, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *ptr_vec = NULL;
    ptr_vec = vec;

    int result = sum_odd(ptr_vec);
    printf("The sum of all odd elements in the array is: %d\n", result);

    return 0;
}

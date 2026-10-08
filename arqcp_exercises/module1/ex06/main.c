#include <stdio.h>
#include "myFunctions.h"

int main(void) {

    int vec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *ptr_vec = NULL;
    ptr_vec = vec;
    int n = sizeof(vec) / sizeof(vec[0]);
    int result = sum_even(ptr_vec, n);

    printf("The sum of all even elements in the array is : %d\n", result);

    return 0;
}
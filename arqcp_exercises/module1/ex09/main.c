#include <stdio.h>
#include "myFunctions.h"

int main() {

    int vec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *ptr_vec = NULL;
    ptr_vec = vec;
    int n = sizeof(vec) / sizeof(vec[0]); // Calculate the number of elements in the array = array size / size of one element
    int minimum;
    int maximum;
    float average;

    get_array_statistics(ptr_vec, n, &minimum, &maximum, &average);

    printf("Minimum: %d\n", minimum);
    printf("Maximum: %d\n", maximum);
    printf("Average: %.2f\n", average);

    return 0;
}

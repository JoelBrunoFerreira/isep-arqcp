/* Exercise 19 */
#include <stdio.h>
#include "myFunctions.h"

int main() {

    int matrix[4][4] = {{1, 2, 3, 4}, {2, 3, 4, 1}, {3, 4, 1, 2}, {4, 3, 2, 1}};

    int result = sum_matrix_values(matrix, 4, 4);
    printf("The matrix sum is: %d\n", result);

    return 0;
}


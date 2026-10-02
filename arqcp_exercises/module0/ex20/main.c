#include <stdio.h>
#include "myFunctions.h"

#define COLS 5

int main() {
    // Test case 1: Lower triangular matrix
    int mat1[][COLS] = {
        {1, 0, 0, 0, 0},
        {2, 3, 0, 0, 0},
        {4, 5, 6, 0, 0},
        {7, 8, 9, 10, 0},
        {11, 12, 13, 14, 15}
    };
    
    printf("Matrix 1 is lower triangular: %d\n", 
           check_lower_triangular_matrix(mat1, 5, 5)); // Should print 1
    
    printf("Sum of lower triangular elements: %d\n", 
           sum_lower_triangular_matrix(mat1, 5)); // Should print 120 (1+2+3+4+5+6+7+8+9+10+11+12+13+14+15)
    
    // Test case 2: Not lower triangular (non-zero above diagonal)
    int mat2[][COLS] = {
        {1, 0, 0, 0, 0},
        {2, 3, 1, 0, 0},  // 1 is above diagonal
        {4, 5, 6, 0, 0},
        {7, 8, 9, 10, 0},
        {11, 12, 13, 14, 15}
    };
    
    printf("Matrix 2 is lower triangular: %d\n", 
           check_lower_triangular_matrix(mat2, 5, 5)); // Should print 0
    
    printf("Sum of lower triangular elements: %d\n", 
           sum_lower_triangular_matrix(mat2, 5)); // Should print -1
    
    // Test case 3: Non-square matrix
    int mat3[][COLS] = {
        {1, 0, 0},
        {2, 3, 0}
    };
    
    printf("Matrix 3 is lower triangular: %d\n", 
           check_lower_triangular_matrix(mat3, 2, 3)); // Should print 0
    
    // Test case 4: 3x3 lower triangular
    int mat4[][COLS] = {
        {5, 0, 0},
        {2, 8, 0},
        {1, 3, 4}
    };
    
    printf("Matrix 4 is lower triangular: %d\n", 
           check_lower_triangular_matrix(mat4, 3, 3)); // Should print 1
    
    printf("Sum of lower triangular elements: %d\n", 
           sum_lower_triangular_matrix(mat4, 3)); // Should print 23 (5+2+8+1+3+4)
    
    return 0;
}
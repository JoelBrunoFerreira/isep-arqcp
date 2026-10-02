#define COLS 5

// Function to check if matrix is lower triangular
int check_lower_triangular_matrix(int mat[][COLS], int lin, int col) {
    // Check if matrix is square
    if (lin != col) {
        return 0;
    }
    
    // Check all elements above main diagonal
    for (int i = 0; i < lin; i++) {
        for (int j = i + 1; j < col; j++) {
            // If any element above diagonal is not zero, it's not lower triangular
            if (mat[i][j] != 0) {
                return 0;
            }
        }
    }
    
    return 1;
}

// Function to sum elements of lower triangular matrix
int sum_lower_triangular_matrix(int mat[][COLS], int lin) {
    // First check if it's a lower triangular matrix
    if (!check_lower_triangular_matrix(mat, lin, lin)) {
        return -1;
    }
    
    int sum = 0;
    
    // Sum all elements on and below the main diagonal
    for (int i = 0; i < lin; i++) {
        for (int j = 0; j <= i; j++) {
            sum += mat[i][j];
        }
    }
    
    return sum;
}
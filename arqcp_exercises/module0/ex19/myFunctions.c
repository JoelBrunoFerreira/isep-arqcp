int sum_matrix_values(int mat[][4], int lin, int col) {
    int sum = 0;
 
    for (int i = 0; i < lin; i++) {
 
        for (int j = 0; j < col; j++) {
 
            sum += mat[i][j];

        }
    }
 
    return sum;
}

int sum_even(int *vec, int n){

    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (vec[i] % 2 == 0) {
            sum += vec[i]; 
        }
    }

    return sum;
}
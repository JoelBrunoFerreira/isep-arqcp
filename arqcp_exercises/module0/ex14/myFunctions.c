int count_value(int vec[], int n, int value) {

    int count = 0;

    for (int i = 0; i < n; i++){

        if (value == vec[i]){
            count++;
        }
    }

    return count;
}
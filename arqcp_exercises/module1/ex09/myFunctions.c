void get_array_statistics(int *vec, int n, int *min, int *max, float *avg) {
     if (n <= 0) {
        *min = 0;
        *max = 0;
        *avg = 0.0;
        return;
    }

    *min = vec[0];
    *max = vec[0];
    int sum = 0;

    for (int i = 0; i < n; i++) {
        if (vec[i] < *min) {
            *min = vec[i]; /* Find min */
        }
        if (vec[i] > *max) {
            *max = vec[i]; /* Find max */
        }
        sum += vec[i]; /* sum */
    }

    *avg = (float)sum / n; /* Average */
}
int sort_without_reps(short *src, int n, short *dest) {
    /* Copy the array to the destination array */
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }

    /*  Sort the array */
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (dest[j] > dest[j + 1]) {
                short temp = dest[j];
                dest[j] = dest[j + 1];
                dest[j + 1] = temp;
            }
        }
    }

    /* Remove duplicates */
    int distinctValues = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0 || dest[i] != dest[i - 1]) {
            dest[distinctValues] = dest[i];
            distinctValues++;
        }
    }
    return distinctValues;
}
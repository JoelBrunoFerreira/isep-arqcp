int sum_odd(int *p) {
    
    /* Point to the second element in the array using pointer arithmetic */
    int *position = p + 1; 
    int sum = 0;

    /* Iterating array on index of 1 */
    /* p[0] it this exercise represent the number of elements in the array */
    for (int i = 1; i <= p[0]; i++) {
        if (*position % 2 != 0) {
            sum += *position;
        }
        position++;
    }

    return sum;
}
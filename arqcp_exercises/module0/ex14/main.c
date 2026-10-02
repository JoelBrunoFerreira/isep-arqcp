/* Exercise 14 */
#include <stdio.h>
#include "myFunctions.h"

int main() {

    printf("How many numbers do you want to read and store in the array?\n");
    int n;
    scanf("%d", &n);

    printf("Enter numbers: \n");
    int vec[n];
    for (int i = 0; i < n; i++){
        scanf("%d", &vec[i]);
    }

    printf("Enter search value: \n");
    int value;
    scanf("%d", &value);

    int result = count_value(vec, n, value);
    printf("The value %d appears %d times in the array\n", value, result);

     for (int i = 0; i < n; i++){
        printf("%d\n", vec[i]);
    }
    
    return 0;
}


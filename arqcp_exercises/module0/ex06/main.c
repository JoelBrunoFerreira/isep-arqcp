/* Exercise 6 */
#include <stdio.h>
#include <limits.h>

int get_greater_digit(int n) {

    int digit;
    int biggest = INT_MIN;

    while(n != 0) {
        digit = n % 10;
        n = n / 10;
        if (digit > biggest){
            biggest = digit;
        }
    }

    return biggest;
}

int main() {

    printf("Enter a number:\n");
    int number;
    scanf("%d", &number);
    int greater = get_greater_digit(number);
    printf("The greater number of the given Integer is: %d\n", greater);

    return 0;
}


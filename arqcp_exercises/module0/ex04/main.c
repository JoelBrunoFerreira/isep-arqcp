/* Exercise 4 */
#include <stdio.h>

int sum_digits(int n) {
    printf("Enter digits to sum!\n");

    int result = 0;

    while (n > 0) {
        int digit;
        scanf("%d", &digit);
        result += digit;
        n--;
    }
   
    return result;

}

int main() {

    printf("How namy digits do you want to sum?\n");
    int numberOfDigits;
    scanf("%d", &numberOfDigits);

    int total = sum_digits(numberOfDigits);
    printf("The total is = %d\n", total);

    return 0;
}


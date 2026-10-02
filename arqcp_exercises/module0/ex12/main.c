/* Exercise 12 */
#include <stdio.h>
#include <string.h>
#include "myFunctions.h"

int main() {

    char x[] = "123.456";
    int x_int = integer_part(x);
    int x_frac = fractional_part(x);

    printf("The integer part of the given number is : %d\n", x_int);
    printf("The fractional part of the given number is : %d\n", x_frac);

    return 0;
}


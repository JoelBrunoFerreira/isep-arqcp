#include <string.h>

int integer_part(char x[]) {
    int num = 0;

    for (int i = 0; x[i] != '.'; i++) {
        num = num * 10 + (x[i] - 48);
    }

    return num;
}


int fractional_part(char x[]) {
    int num = 0;
    int digit;
    int reverse = 0;
    int length = strlen(x);
    
    /* Get numbers after the '.' character */
    for (int i = length-1; x[i] != '.'; i--) {
        num = num * 10 + (x[i] - 48);
    }

    /* Reverse the number */
    while (num != 0){
        digit = num % 10;
        reverse = reverse * 10 + digit;
        num = num / 10;
    }
    
    return reverse;
}
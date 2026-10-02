/* Exercise 15 */
#include <stdio.h>
#include "myFunctions.h"

int main() {

    printf("Enter a string: \n");
    char str[100];
    scanf("%[^\n]", str);

    int result = count_words(str);
    printf("The given string has %d words\n", result);

    return 0;
}


/* Exercise 13 */
#include <stdio.h>
#include "myFunctions.h"

int main() {

    char str[30];
    printf("Enter a string: \n");
    /* Read a line -> String with spaces*/
    scanf("%[^\n]", str);

    int asciiCode;
    printf("Enter ASCII character code: \n");
    scanf("%d", &asciiCode);

    int result = count_char(str, asciiCode);
    printf("The ASCII character appears %d times in the given string\n", result);
    return 0;
}


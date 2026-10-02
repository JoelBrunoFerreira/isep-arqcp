/* Exercise 16 */
#include <stdio.h>
#include "myFunctions.h"

int main() {

    printf("Enter some string: \n");
    char str[150];
    /* Read a line -> String with spaces*/
    scanf("%[^\n]", str);

    int result = fake_hash(str);
    printf("The hash for the given string is : %d\n", result);

    return 0;
}


/* Exercise 17 */
#include <stdio.h>
#include "myFunctions.h"

int main() {

    printf("Enter some string: \n");
    char str[150];
    /* Read a line -> String with spaces*/
    scanf("%[^\n]", str);

    printf("Enter hash code: \n");
    int hash;
    scanf("%d", &hash);

    int result = check_string(str, hash);
    printf("Verification : %d\n", result);

    return 0;
}


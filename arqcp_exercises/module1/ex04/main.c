#include <stdio.h>
#include "myFunctions.h"

int main() {

    char str[] = "Instituto Superior de Engenharia do Porto";
    char *ptr_str = NULL;
    ptr_str = str;
    printf("Original: %s\n", str);

    capitalize(ptr_str);
    printf("Capitalized: %s\n", str);

    return 0;
}
#include <stdio.h>
#include "myFunctions.h"

int main() {

    char str[] = "     the     numBEr     must  be   saved     ";
    char *ptr_str = NULL;
    ptr_str = str;

    trim_string(ptr_str);
    printf("%s\n", str);

    return 0;
}

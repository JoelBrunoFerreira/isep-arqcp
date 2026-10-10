#include <stdio.h>
#include "myFunctions.h"

int main(){
    char str[] = "This is a test...";
    char c = 'V';

    char* result = NULL;
    result = where_is(str,c);

    if (result == NULL)
    {
        printf("The character '%c' wasn't found.\n",c);
    }
    else
    {
        printf("The character '%c' was found at address: %p\n",c, result);
    }
    
    return 0;

}
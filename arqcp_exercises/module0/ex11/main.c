/* Exercise 11 */
#include <stdio.h>
#include "convert.h"

int main(){
    char* str = "12345";
    
    int result = string_to_int(str);
    printf("String to number : %d\n", result);
    
    return 0;
}


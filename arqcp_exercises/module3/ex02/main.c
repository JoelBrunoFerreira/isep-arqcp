#include <stdio.h>
#include "asm.h"

/**
Implement a function void str_copy_roman(char* ptr1, char* ptr2) that copies the string 
pointed by ptr1 to the string pointed by ptr2, replacing each occurrence of the character ’u’ by ’v’, 
considering lower case characters only.
*/

int main(void) {

    char str1[] = "lupus in fabula";
    char str2[50];

    str_copy_roman(str1, str2);

    printf("Original string: %s\n", str1);
    printf("Modified string: %s\n", str2);

	return 0;
}
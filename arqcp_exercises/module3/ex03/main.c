#include <stdio.h>
#include "asm.h"

/**
 Implement a function void str_copy_roman2(char* ptr1, char* ptr2) that co-
pies the string pointed by ptr1 to the string pointed by ptr2, replacing each oc-
currence of the character ’u’ by the character ’v’, considering lower and upper
case characters.
 */

int main(void) {

	char str1[] = "Lupus in fabula Ubi sunt";
	char str2[64];

	str_copy_roman2(str1, str2);
	printf("Original string: %s\n", str1);
	printf("Modified string: %s\n", str2);

	return 0;
}
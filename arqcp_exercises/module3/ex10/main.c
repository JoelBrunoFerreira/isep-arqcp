#include <stdio.h>
#include "asm.h"

/**
Implement a function void str_cat(char* ptr1, char* ptr2, char* ptr3) that
concatenates, in a string pointed by ptr3, the strings pointed by ptr1 and ptr2,
which have a maximum length of 40 bytes each.
 */

int main(void) {
	char str1[41] = "Joel "; // 40 + 1 for null terminator
	char str2[41] = "Bruno"; // 40 + 1 for null terminator
	char str3[82]; // 40 + 40 + 1 for null terminator

	str_cat(str1, str2, str3);

	printf("Concatenated String: %s\n", str3);

	return 0;
}
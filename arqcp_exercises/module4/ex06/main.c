#include <stdio.h>
#include "asm.h"

/*
Implement the function int test_different(char *a, char *b) that detects if two strings are
equal. If the strings are different, the function should return 1, or 0 otherwise.
*/

int main(void) {
	char str1[] = "Hello, World!";
	char str2[] = "Hello, World!";
	char str3[] = "Hello, C Programming!";

	int result1 = test_different(str1, str2);
	int result2 = test_different(str1, str3);

	printf("Comparing \"%s\" and \"%s\": %d\n", str1, str2, result1); // Expected output: 0
	printf("Comparing \"%s\" and \"%s\": %d\n", str1, str3, result2); // Expected output: 1

	return 0;
}
#include <stdio.h>
#include "asm.h"

/*
Implement in Assembly the function int calc(int a, int * b, int c) with the behaviour 
presented in Listing 1. Note: Use in Assembly the required local variables.

Listing 1 - C implementation of calc
-------------------------------------
int calc(int a, int *b, int c) {
	int z = a * 4 + (*b);
	return (c-6)*z;
}
*/

int main(void) {
	int a = 2;
	int b = 3;
	int c = 10;
	int result = calc(a, &b, c);
	printf("Result: %d\n", result); // Expected output: Result: 44

	return 0;
}
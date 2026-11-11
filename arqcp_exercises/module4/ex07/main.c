#include <stdio.h>
#include "asm.h"

/**
Implement the function int count_even(short *vec, int n) that given the start address of a
vector of shorts with ’n’ elements, returns the number of even numbers in the vector.
*/

int main(void) {
	short vec[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int n = sizeof(vec) / sizeof(vec[0]);

	int result = count_even(vec, n);
	printf("Number of even numbers: %d\n", result);

	return 0;
}
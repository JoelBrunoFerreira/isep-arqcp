#include <stdio.h>
#include "asm.h"

/**
Implement a function int vec_sum(int* ptr, short num) that returns the sum
of all the elements of an array of type int, pointed by ptr, with short num ele-
ments.

Then, implement another function int vec_avg(int* ptr, short num) in As-
sembly that uses the value returned by int vec_sum(int* ptr, short num) to
compute the average.
*/

int main(void) {

	int array[] = {1, 2, 3, 4, 5};
	short num_elements = sizeof(array) / sizeof(array[0]);
	
	int sum = vec_sum(array, num_elements);
	printf("Sum of array elements: %d\n", sum);

	int avg = vec_avg(array, num_elements);
	printf("Average of array elements: %d\n", avg);

	return 0;
}

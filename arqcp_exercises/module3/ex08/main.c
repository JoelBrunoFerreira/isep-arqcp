#include <stdio.h>
#include "asm.h"

/**
Implement the function int test_even(int x) that tests if the number x is even.
The function should return one (1) if it is even or zero (0) if it is odd.

Use the previous function to implement another function int vec_sum_even(int*
ptr, int num) in Assembly that returns the sum of all the even elements of an
array of type int pointed by ptr, with num elements.
 */

int main(void) {
	/*
	printf("Enter an integer: ");
	int x;
	scanf("%d", &x);

	int result = test_even(x);

	if (result == 1) {
		printf("The number %d is even.\n", x);
	} else {	
		printf("The number %d is odd.\n", x);
	}	
	*/

	int arr[] = {1, 2, 3, 4, 5, 6};
	int size = sizeof(arr) / sizeof(arr[0]);
	int sum = vec_sum_even(arr, size);
	printf("\n");
	printf("======================================\n");
	printf("Sum of even elements in the array: %d\n", sum);
	printf("======================================\n");

	return 0;
}
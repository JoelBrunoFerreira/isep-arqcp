#include <stdio.h>
#include "asm.h"

/**
Implement a function int* vec_search(int* ptr, int num, int x) that sear-
ches int x in an array of type int, pointed by ptr, with int num elements, and
returns the memory address of it’s first occurrence or zero if not found.
 */

int main(void) {

	int arr[] = {4, 2, 3, 5, 2, 1, 7, 9, 2};
	int num = sizeof(arr) / sizeof(arr[0]);
	int x = 8;

	int* result = vec_search(arr, num, x);
	if (result != NULL) {
		printf("Found element %d at address %p\n", x, result);
	} else {
		printf("Element %d not found in the array.\n", x);
	}

	return 0;
}
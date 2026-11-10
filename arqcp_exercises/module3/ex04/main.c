#include <stdio.h>
#include "asm.h"

/**
 Implement a function void vec_add_three(short* ptr, int num) that adds three (3)
to all the elements of an array of type short, with int num elements and
pointed by ptr.
 */

int main(void) {

	short vec[5] = {1, 2, 3, 4, 5};
	int num = sizeof(vec) / sizeof(vec[0]);

	vec_add_three(vec, num);
	
	printf("After adding three to each element in the array:\n");
	for (int i = 0; i < num; i++) {
		printf("%d ", vec[i]); // Print modified values
	}
	printf("\n");

	return 0;
}
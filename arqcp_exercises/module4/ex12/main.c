#include <stdio.h>
#include "asm.h"

/*
Implement the function int count_bits_zero(int x) that counts the number of inactive bits
(with the value 0) in a number x.
	a) In C.
	b) In Assembly.
	c) Use the Assembly function developed in b) in another Assembly function 
	int vec_count_bits_zero(int* ptr, int num) that counts the total number of active 
	bits in a vector of integers. 
*/

int main(void) {
	int num = 29; // Binary: 0001 1101, has 3 zero bits
	int result = count_bits_zero(num);
	printf("Number of zero bits in %d: %d\n", num, result);

	int vec[] = {29, 15, 8}; // 29(3 zeros), 15(0 zeros), 8(3 zeros) => total 6 zeros
	int vec_size = sizeof(vec) / sizeof(vec[0]);
	int vec_result = vec_count_bits_zero(vec, vec_size);
	printf("Total number of zero bits in vector: %d\n", vec_result);

	return 0;
}

/* Expected Output:
 * 29 em 32 bits tem 28 bits a 0.
 * 15 (0b1111) tem 28 zeros.
 * 8 (0b1000) tem 31 zeros.
 */
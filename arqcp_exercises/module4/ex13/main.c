#include <stdio.h>

/*
Implement in C the functions:
• short rotate_left (short num, char nbits) - this function rotates the value num, nbits to
the left.
• short rotate_right (short num, char nbits) - this function rotates the value num, nbits
to the right.
 */

short rotate_left(short num, char nbits) {
	return (num << nbits) | (num >> (16 - nbits));
}

short rotate_right(short num, char nbits) {
	return (num >> nbits) | (num << (16 - nbits));
}

int main(void) {

	short num = 0x1234; /* short has 16 bits */
	char nbits = 4;

	short left_rotated = rotate_left(num, nbits);
	short right_rotated = rotate_right(num, nbits);

	printf("Original: 0x%04X\n", num);
	printf("Left rotated by %d: 0x%04X\n", nbits, left_rotated);
	printf("Right rotated by %d: 0x%04X\n", nbits, right_rotated);

	return 0;
}
#include <stdio.h>
#include "asm.h"

// Area of a trapezoid = ((len1 + len2) * height) / 2

int main(void) {
	int len1, len2, height, res;

	printf("Comprimento 1: ");
	scanf("%d", &len1);

	printf("Comprimento 2: ");
	scanf("%d", &len2);

	printf("Altura: ");
	scanf("%d", &height);

	res = get_area(len1, len2, height);
	printf("Area: %d\n", res);

	return 0;
}

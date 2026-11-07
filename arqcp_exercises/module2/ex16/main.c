#include <stdio.h>
#include "asm.h"

// Operations:
// -------------------
// a) Multiplies by 3
// b) Adds 6
// c) Divides by 3
// d) Adds 12
// e) Subtracts num
// f) Subtracts 4


int main(void) {
	int n, res;

	printf("Insira um número: ");
	scanf("%d", &n);

	res = steps(n);
	printf("Resultado: %d\n", res);

	return 0;
}

#include <stdio.h>
#include "asm.h"

// Formula: ((a * b) - (c * a)) / d

int main(void) {
	int a, b, c, d, res;

	printf("Valor para a: ");
	scanf("%d", &a);

	printf("Valor para b: ");
	scanf("%d", &b);

	printf("Valor para c: ");
	scanf("%d", &c);

	printf("Valor para d: ");
	scanf("%d", &d);

	res = compute(a, b, c, d);
	printf("Resultado: %d\n", res);

	return 0;
}

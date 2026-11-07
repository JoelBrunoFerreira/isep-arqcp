#include <stdio.h>
#include "asm.h"

int main(void) {

	int n, res;

	printf("Valor sigma: (n >= 1) ");
	scanf("%d", &n);

	res = sigma(n);
	printf("Resultado = %d\n", res);
	
	return 0;
}

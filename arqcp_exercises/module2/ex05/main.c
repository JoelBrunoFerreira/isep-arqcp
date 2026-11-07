#include <stdio.h>
#include "asm.h"

int main(void) {
	int op1, op2, res;

	printf("Valor op1:");
	scanf("%d", &op1);

	printf("Valor op2:");
	scanf("%d", &op2);

	res = parallel(op1, op2);
	//printf("sum = %d:0x%x\n", res, res);
	printf("Resultado: %d\n", res);

	return 0;
}
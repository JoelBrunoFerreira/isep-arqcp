#include <stdio.h>
#include "asm.h"

int main(void) {
	int op1, res;

	printf("Valor op1:");
	scanf("%d", &op1);

	res = three_halves(op1);
	//printf("sum = %d:0x%x\n", res, res);
	printf("Resultado: %d\n", res);
	
	return 0;
}
#include <stdio.h>
#include "asm.h"

int main(void) {
	int op1, op2, op3, res;

	printf("Valor para x:");
	scanf("%d", &op1);

	printf("Valor para y:");
	scanf("%d", &op2);

	printf("Valor para z:");
	scanf("%d", &op3);

	res = my_remainder(op1, op2, op3);
	//printf("sum = %d:0x%x\n", res, res);
	printf("------------------------\n");
	printf("Resto da divisão: %d\n", res);
	printf("------------------------\n");

	return 0;
}

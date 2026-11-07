#include <stdio.h>
#include "asm.h"

int main(void) {
	int op1, op2, res;

	printf("Valor para x:");
	scanf("%d", &op1);

	printf("Valor para y:");
	scanf("%d", &op2);

	res = is_greater(op1, op2);
	if(res == 1)
		printf("x é maior que y\n");
	else if(res == -1)
		printf("x é igual a y\n");
	else
		printf("x não é maior que y\n");

	return 0;
}

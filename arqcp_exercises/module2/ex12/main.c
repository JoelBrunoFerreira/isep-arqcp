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

	res = in_order(op1, op2, op3);
	if(res == 1)
		printf("Os valores estao em ordem decrescente.\n");
	else
		printf("Os valores nao estao em ordem decrescente.\n");

	return 0;
}

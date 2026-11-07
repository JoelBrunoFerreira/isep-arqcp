#include <stdio.h>
#include "asm.h"

int main(void) {
	int op1, op2, res;

	printf("Valor para x:");
	scanf("%d", &op1);

	printf("Valor para y:");
	scanf("%d", &op2);
	
	res = is_multiple(op1, op2);
	
	printf("------------------------------\n");
	if (res == 1) {
		printf("%d é múltiplo de %d\n", op1, op2);
	} else {
		printf("%d não é múltiplo de %d\n", op1, op2);
	}
	printf("------------------------------\n");

	return 0;
}
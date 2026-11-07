#include <stdio.h>
#include "asm.h"

int main(void) {
	int op1, op2, op3, res;

	printf("Horas: (O valor deve estar entre 0 e 500)");
	scanf("%d", &op1);

	printf("Minutos: (O valor deve estar entre 0 e 59)");
	scanf("%d", &op2);

	printf("Segundos: (O valor deve estar entre 0 e 59)");
	scanf("%d", &op3);

	res = time_sec(op1, op2, op3);
	//printf("sum = %d:0x%x\n", res, res);
	printf("------------------------\n");
	printf("Total em segundos: %d\n", res);
	printf("------------------------\n");

	return 0;
}
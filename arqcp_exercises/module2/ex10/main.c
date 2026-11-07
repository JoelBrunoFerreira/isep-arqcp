#include <stdio.h>
#include "asm.h"

int main(void) {
	printf("NOTA IMPORTANTE\n");
	printf("===============\n");
	printf("O intervalo típico de um long long é de -9.223.372.036.854.775.808 a 9.223.372.036.854.775.807. \n");
	printf("Use valores dentro deste intervalo, pois é geralmente armazenado como um número de 64 bits (8 bytes). \n");
	printf("\n");
	long long op1, op2, res;

	printf("Valor op1:");
	scanf("%lld", &op1);

	printf("Valor op2:");
	scanf(" %lld", &op2);

	res = big_sum(op1, op2);
	printf("Resultado: %lld \n", res);

	return 0;
}

// Exemplo de some de dois números long long
// 5.000.000.000 + 10.000.000.000 = 15.000.000.000

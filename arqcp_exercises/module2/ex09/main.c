#include <stdio.h>
#include "asm.h"

int main(void) {
	int op1, res;

	printf("Inserir o número de garrafas:");
	scanf("%d", &op1);

	res = six_packs(op1);
	
	printf("------------------------------\n");
	if(res == 1) {
		printf("É preciso: %d six_pack\n", res);
	}
	else if (res > 1) {
		printf("São precisos: %d six_packs\n", res);
	} else {
		printf("Não é preciso nenhum six_pack\n");
	}
	printf("------------------------------\n");
	
	return 0;
}
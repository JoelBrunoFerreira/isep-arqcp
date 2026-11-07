#include <stdio.h>
#include "asm.h"

int main(void) {
	int current, desired, res;

	printf("Valor atual:");
	scanf("%d", &current);

	printf("Valor desejado:");
	scanf("%d", &desired);

	res = needed_time(current, desired);
	if(res == 0) {
		printf("A temperatura já está no valor desejado.\n");
		return 0;
	}
	printf("Tempo necessário para atingir a temperatura desejada: %d minutos.\n", res);

	return 0;
}

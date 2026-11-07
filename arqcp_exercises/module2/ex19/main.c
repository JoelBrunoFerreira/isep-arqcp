#include <stdio.h>
#include "asm.h"

int main(void) {
	int num, res;
	printf("Enter a number: ");
	scanf("%d", &num);

	res = check_num(num);

	switch (res){
	case 1:
		printf("The number is even and negative.\n");
		break;
	case 2:
		printf("The number is odd and negative.\n");
		break;
	case 3:
		printf("The number is even and positive.\n");
		break;
	case 4:
		printf("The number is odd and positive.\n");
		break;
	default:
		printf("The number is zero.\n");
		break;
	}

	return 0;
}

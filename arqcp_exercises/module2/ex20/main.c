#include <stdio.h>
#include "asm.h"

int main(void) {
	int salary, code, res;

	printf("Enter current salary:");
	scanf("%d", &salary);

	printf("Enter code:");
	scanf("%d", &code);

	res = new_salary(salary, code);
	printf("new_salary = %d\n", res);

	return 0;
}

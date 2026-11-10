#include <stdio.h>
#include "asm.h"

int main(void) {

	char* s1 = "12345";
	char s2[] = "5xx5x5";
	char* s3 = "";
	char* s4 = "55555";
	
	printf("Quantos 5's tem cada string!\n");
	printf("A string: %s tem %d\n", s1, five_count(s1));
	printf("A string: %s tem %d\n", s2, five_count(s2));
	printf("\"%s\" tem %d\n", s3, five_count(s3));
	printf("A string: %s tem %d\n", s4, five_count(s4));
	
	return 0;
}
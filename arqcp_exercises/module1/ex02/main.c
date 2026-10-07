#include <stdio.h>

int main(void) {
    
    double a = 3.14;
    int b = 10;
    char c = 'A';

    double *ptr_a = &a;
    int *ptr_b = &b;
    char *ptr_c = &c;

    printf("a: address=%p, value=%.2f, size=%zu bytes\n", &a, a, sizeof a);
    printf("b: address=%p, value=%d, size=%zu bytes\n", &b, b, sizeof b);
    printf("c: address=%p, value=%c, size=%zu bytes\n", &c, c, sizeof c);

    printf("====================================\n");
    
    printf("ptr_a: address=%p, value=%p, size=%zu bytes\n", &ptr_a, ptr_a, sizeof ptr_a);
    printf("ptr_b: address=%p, value=%p, size=%zu bytes\n", &ptr_b, ptr_b, sizeof ptr_b);
    printf("ptr_c: address=%p, value=%p, size=%zu bytes\n", &ptr_c, ptr_c, sizeof ptr_c);

    return 0;
}
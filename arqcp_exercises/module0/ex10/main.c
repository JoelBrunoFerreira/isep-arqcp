/* Exercise 10 */
#include <stdio.h>
#include "size_string.h"

int main() {

    char x[] = "I will master ARQCP";

    printf("Size =%lu\n", sizeof(x));
    printf("Size =%u\n", size_string_wrong (x));
    printf("Size =%u\n", size_string_correct(x));

    char y[25] = "I will master ARQCP";
    printf("\n");

    printf("Size =%lu\n", sizeof(y));
    printf("Size =%u\n", size_string_wrong (y));
    printf("Size =%u\n", size_string_correct(y));

    return 0;
    
    /* Resposta */
    /* =========*/
    
    /*
    O printf da linha 9 devolve o comprimento da string incluindo o 'end character \0'. Total: 19 + 1 = 20
    
    O printf da linha 16 devolve o tamanho completo do array definido na inicialização, isto é = 25.
    Independentemente de a string ser a mesma.
    */

}


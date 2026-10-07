#include <stdio.h>
#include "myFunctions.h"

int main(void){

    int a = 3;
    int b = 4;
    char *s1;
    char *s2;

    /*
     * swap_nums recebe os enderecos de a e b. Assim, consegue alterar
     * os valores das variaveis originais, em vez de trocar apenas copias.
     */
    swap_nums(&a,&b);

    printf("a is %d\n", a);
    printf("b is %d\n", b);

    printf("=============================\n");

    /*
     * s1 e s2 sao ponteiros para strings. Para trocar os proprios ponteiros
     * no chamador, passamos os seus enderecos (&s1 e &s2). A funcao recebe
     * esses enderecos como char ** e troca os valores apontados.
     */
    s1 = "I should print second";
    s2 = "I should print first";
    swap_pointers(&s1, &s2);
    printf("s1 is %s\n", s1);
    printf("s2 is %s\n", s2);
    return 0;
}
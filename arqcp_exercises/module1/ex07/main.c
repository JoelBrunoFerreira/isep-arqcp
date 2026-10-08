#include <stdio.h>
#include "myFunctions.h"

int main(){
    
    char str[] = "heLL0 world!";
    char *pStr = NULL;
    pStr = str; // como é array não necessita do '&' para acessar o endereço.

    capitalize2(pStr);

    printf("%s\n", pStr);  

    return 0;
}
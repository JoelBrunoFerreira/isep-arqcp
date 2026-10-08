#include <stdio.h>
#include "myFunctions.h"

int main(void){
    int n = 10;
    
    int vec1[] = {1,2,3,4,5,6,7,8,9,10};
    int *pVec1 = NULL;
    pVec1 = vec1; //como é array, não necessita do '&' para acessar o endereço!
    
    int vec2[n];
    int *pVec2 = NULL;
    pVec2 = vec2;

    copy_vec(pVec1,n,pVec2);
    
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", vec2[i]);
    }
    
    return 0;
}
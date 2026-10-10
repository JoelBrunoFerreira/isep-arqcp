#include <stdio.h>
#include "myFunctions.h"

int main(){
    int n = 10;
    int vec[] = {1,5,9,4,1,2,10,7,8,9};
    
    array_sort(vec,n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", vec[i]);
    }

    return 0;
}

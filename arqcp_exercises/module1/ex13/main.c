#include <stdio.h>
#include "myFunctions.h"

int main() {

    short src[] = {3, 2, 1, 2, 4, 3, 5};
    int n = sizeof(src) / sizeof(src[0]);
    short dest[n];

    short *ptr_src = NULL;
    short *ptr_dest = NULL;
    ptr_src = src;
    ptr_dest = dest;
    
    sort_without_reps(ptr_src, n, ptr_dest);
  
    int sorted = sort_without_reps(src, n, dest);
    for (int i = 0; i < sorted; i++) {
        printf("%d ", dest[i]);
    }
    printf("\n");

    return 0;
}
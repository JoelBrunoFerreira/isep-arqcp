/* Exercise 9 */
#include <stdio.h>
#include "average.h"

int main(){

    int v[] = {1,2};
    int r = 0;
    r = average1(v[0], v[1]);
    printf("average1 = %d\n", r);

    /* =========================================== */

    int v2[] = {1,2,3,4,5,6,7,8,9};
    int r2 = 0;

    /* Array Length */
    int ArrayLength = sizeof(v2) / sizeof(v2[0]);
    r2 = average2(v2, ArrayLength);
    printf("average2 = %d\n", r2);

    return 0;

}


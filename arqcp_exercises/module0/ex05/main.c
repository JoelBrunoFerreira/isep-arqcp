/* Exercise 5 */
#include <stdio.h>

int cmp(int a, int b) {

    if (a < b) {
        return -1;
    } else if (a == b){
        return 0;
    } else {
        return 1;
    }
    
}

int main() {

    int caseOne = cmp(1, 3);
    int caseTwo = cmp(2, 2);
    int caseThree = cmp(3, 1);

    printf("Case One : %d\n", caseOne);
    printf("Case Two : %d\n", caseTwo);
    printf("Case Three : %d\n", caseThree);

    return 0;
}


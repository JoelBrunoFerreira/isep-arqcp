/* Exercise 3 */
#include <stdio.h>

int mul(int a, int b) {

    int result = 0;
    while (b != 0) {
        
        result += a;
        b--;
    }
    return result;
}

int main() {

    printf("The result is = %d\n", mul(3, 4));

    return 0;
}


/* Exercise 1 */
#include <stdio.h>

int main() {

    char sizeOfChar;
    int sizeOfInt;
    unsigned int sizeOfUnsignedInt;
    long sizeOfLong;
    short sizeOfShort;
    long long sizeOfLongLong;
    float sizeOfFloat;
    double sizeOfDouble;
    
    printf("Size of char = %zu byte\n", sizeof(sizeOfChar));
    printf("Size of int = %zu bytes\n", sizeof(sizeOfInt));
    printf("Size of unsigned int = %zu bytes\n", sizeof(sizeOfUnsignedInt));
    printf("Size of long = %zu bytes\n", sizeof(sizeOfLong));
    printf("Size of short = %zu bytes\n", sizeof(sizeOfShort));
    printf("Size of long long = %zu bytes\n", sizeof(sizeOfLongLong));
    printf("Size of float = %zu bytes\n", sizeof(sizeOfFloat));
    printf("Size of double = %zu bytes\n", sizeof(sizeOfDouble));

    return 0;
}


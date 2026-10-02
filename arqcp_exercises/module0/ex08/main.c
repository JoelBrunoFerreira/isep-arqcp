/* Exercise 8 */
#include <stdio.h>

char get_ascii_code(int c) {

    printf("Enter a Number:\n");
    scanf("%d", &c);
    return c; 

}

int main() {

    char asciiChar = get_ascii_code(97);
    printf("The ascii char for the given number is : %c\n", asciiChar);

    return 0;
}


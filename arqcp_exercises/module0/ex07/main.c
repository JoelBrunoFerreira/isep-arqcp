/* Exercise 7 */
#include <stdio.h>

int get_ascii_code(char c) {

    printf("Enter a Character:\n");
    scanf("%c", &c);
    return c; 

}

int main() {

    int asciiValue = get_ascii_code('a');
    printf("The ascii number for the given char is : %d\n", asciiValue); 

    return 0;
}


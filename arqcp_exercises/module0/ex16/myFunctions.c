#include <string.h>

int fake_hash(char str[]) {

    int sum = 0;
    int lenght = strlen(str);

    for (int i = 0; i < lenght; i++){
        sum += str[i];
    }
    
    return sum;
}
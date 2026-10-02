#include <string.h>

int count_char(char str[], int c) {

    int count = 0;
    int length = strlen(str);
    
    for (int i = 0; i < length; i++){
        if (c == str[i]){
            count++;
        }
    }

    return count;
}
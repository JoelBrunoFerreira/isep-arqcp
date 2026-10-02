#include <string.h>

int check_string(char str[], int h){

    int sum = 0;
    int lenght = strlen(str);

    for (int i = 0; i < lenght; i++){
        sum += str[i];
    }

    if (sum == h){
        return 1;
    } else {
        return 0;
    }

}
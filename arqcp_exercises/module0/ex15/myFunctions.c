#include <string.h>

int count_words(char str[]) {

    int length = strlen(str);
    int numberOfWords = 0;

    if (length > 0){
        for (int i = 0; i <= length; i++){
            if (str[i] == ' ' || (str[i] == '\0' && str[0] != ' ')){
                numberOfWords++;
            }
        }
            
    }
    
    return numberOfWords;
}
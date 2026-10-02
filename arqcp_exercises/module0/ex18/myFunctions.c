#include <string.h>

int find_pattern(char str[], char patt[]) {
    int count = 0;
    int str_len = strlen(str);
    int patt_len = strlen(patt);
    
    // If pattern is empty or longer than string, return 0
    if (patt_len == 0 || patt_len > str_len) {
        return 0;
    }
    
    // Check each possible starting position in the string
    for (int i = 0; i <= str_len - patt_len; i++) {
        int found = 1;
        
        // Check if pattern matches starting at position i
        for (int j = 0; j < patt_len; j++) {
            if (str[i + j] != patt[j]) {
                found = 0;
                break;
            }
        }
        
        if (found) {
            count++;
        }
    }
    
    return count;
}
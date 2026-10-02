/* Exercise 18 */
#include <stdio.h>
#include <string.h>
#include "myFunctions.h"

int main() {
    int x = find_pattern("ola Pedro, ola Laura", "la");
    printf("Result: %d\n", x);
    
    // Additional test cases
    printf("Test 1: %d\n", find_pattern("hello world", "lo"));
    printf("Test 2: %d\n", find_pattern("abababa", "aba"));
    printf("Test 3: %d\n", find_pattern("abc", "xyz"));
    
    return 0;
}
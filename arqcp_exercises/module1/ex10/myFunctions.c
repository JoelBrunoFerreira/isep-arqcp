#include <stdio.h>

char* where_is(char *str, char c){
    while (*str!='\0') // Iterate through the characters in the string until the null terminator is encountered.
    {
        if (*str == c) // Check if the current character matches the target character 'c'.
        {
            return str; // Return the address of the current character, indicating the first occurrence of 'c'.
        }
        str++; // Move to the next character.
    }
	// If target character isn't found, return null.
    return NULL;
}
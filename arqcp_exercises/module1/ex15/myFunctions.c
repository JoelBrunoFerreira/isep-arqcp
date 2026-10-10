void trim_string(char *str) {
    if (*str == '\0') {
        return;
    }

    char *readPointer = str; /* Read pointer */
    char *writePointer = str; /* Write pointer */
    int isWord = 0; /* Flag to check if we are inside a word  --> Boolean: 0 to false // 1 to true */

    while (*readPointer) {
        if (*readPointer == ' ') {
            if (isWord) {
                *writePointer++ = ' '; /* Set one space after word*/
                isWord = 0;
            }
        } else {
            *writePointer++ = *readPointer;
            isWord = 1;
        }
        readPointer++; /* Move to next */
    }

    /* Remove extra spaces in the end of the line */
    while (writePointer > str && (*(writePointer - 1) == ' ')) {
        writePointer--;
    }

    /* Write new null terminator character --> end of the string */
    *writePointer = '\0';
} 
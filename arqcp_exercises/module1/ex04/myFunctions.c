void capitalize(char *str) {

    if (str[0] != '\0'){ // Check if the string is not empty
        while (*str) {
        if (*str >= 'a' && *str <= 'z') {
            *str = *str - ('a' - 'A');
        }
        str++;
        }
    }
}
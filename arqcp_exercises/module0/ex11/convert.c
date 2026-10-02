int string_to_int(char str[]) {
    int num = 0;

     for (int i = 0; str[i] != '\0'; i++) {
        num = num * 10 + (str[i] - 48);
    }

    return num;

}

/* NOTE */
/*
We have used str[i] – 48 to convert the number character to their numeric values. 
For example the ASCII value of character ‘5’ is 53, so 53 – 48 = 5 which is its numeric value.
*/
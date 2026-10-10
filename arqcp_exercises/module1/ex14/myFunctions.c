int count_words(char *str){
    int wordCount = 0;
    int inWord = 0;

    while (*str!='\0') // Iterate through the characters in the string until the null terminator is encountered.
    {
        if ((*str <= 122 && *str >= 97) || (*str <= 90 && *str >= 65)|| (*str <= 57 && *str >= 48)){ // Check if the current character is a letter (a-z or A-Z).
            
			if (inWord==0)// If not in a word, increment the word count and set inWord to true.
            {
                wordCount++;
                inWord=1;
            }
        }
        else // If the current character is not a letter, set inWord to false.
        {
            inWord = 0;
        }
        str++; // Move to the next character.
    }
    return wordCount;
}
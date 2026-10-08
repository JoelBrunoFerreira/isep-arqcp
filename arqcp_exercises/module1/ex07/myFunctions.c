void capitalize2(char *str){
	// Iterate through the characters until the null terminator is encountered.
    while(*str)
    {
		// Check if the current character is a lowercase letter (between 'a' and 'z' in ASCII).
        if ( *str >= 'a' && *str <= 'z' )
        {
			// Convert the lowercase letter to uppercase by subtracting 32 from its ASCII value.
            *str = *str - 32; //in ASCII 'A' = 65, 'a' = 97 so 97-65 = 32;
        }
		// Move to the next character.
        str++;
    }
}
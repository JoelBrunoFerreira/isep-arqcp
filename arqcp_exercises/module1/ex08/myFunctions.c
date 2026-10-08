int sum_integer_bytes(unsigned int *p){

    int sum = 0;
    unsigned char *bytePointer = (unsigned char *)p;  // Treat the integer as an array of bytes

    for (unsigned int i = 0; i < sizeof(unsigned int); i++) {
        sum += *bytePointer;  // Add the current byte to the sum
        bytePointer++;        // Move to the next byte
    }

    return sum;
}
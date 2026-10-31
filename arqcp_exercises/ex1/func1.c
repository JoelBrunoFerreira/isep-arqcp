/*
1191843 - Joel Bruno Teixeira Ferreira - 2NC
*/

int low_pressure(unsigned int *x) {
    unsigned char *pressure = (unsigned char *)x; // Cast the pointer to unsigned char to access individual bytes. 
                                                  // Because each tire's pressure is stored in a byte, we can treat 
                                                  // the unsigned int as an array of 4 bytes.

    for (unsigned int i = 0; i < sizeof(*x); i++) { // Loop through each byte of the unsigned int
        /*
        if (pressure[i] < 0xFE) { // Check if the pressure is below 254 (0xFE)
            return 1; // Return 1 if any tire has low pressure
        }
        */
        if (*(pressure + i) < 0xFE) { // Check if the pressure is below 254 (0xFE)
            return 1; // Return 1 if any tire has low pressure
        }
    }

    return 0; // Return 0 if all tires have sufficient pressure
}

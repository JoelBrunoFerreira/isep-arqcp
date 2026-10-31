/*
1191843 - Joel Bruno Teixeira Ferreira - 2NC
*/

#include "program_functions.h"

int check_tires(unsigned int *cars, int n, unsigned int **fill) {
    int count = 0; // Initialize count of cars needing filling

    while (n > 0) { // Loop through each car
        if (low_pressure(cars)) { // Check if the current car has low pressure
            *fill = cars; // Store the pointer to the car needing filling
            fill++; // Move to the next position in the fill array
            count++; // Increment the count of cars needing filling
        }

        cars++; // Move to the next car
        n--; // Decrement the number of cars left to check
    }

    return count; // Return the total count of cars needing filling
}

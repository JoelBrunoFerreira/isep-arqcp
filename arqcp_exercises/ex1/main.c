/*
1191843 - Joel Bruno Teixeira Ferreira - 2NC
*/

#include <stdio.h>
#include "program_functions.h"

#define NCARS 5

int main (void) {

    unsigned int cars[NCARS]={0xFFFFFFFF,0xFFFAFFFA,0x00000000,0xFCFDEFAB,0xFFFFFFFF};
    unsigned int *fill[NCARS]; // Array of pointers to store cars that need filling

    /*
    // Uncomment the following lines to test the low_pressure function directly
    int low_pressure_result = low_pressure(&cars[4]); // Check if any car has low pressure
    printf("Low pressure check result: %d\n", low_pressure_result); // Print the result of the low pressure check
    */

    int fill_count = check_tires(cars, NCARS, fill); // Call the function to check tires and get the count of cars needing filling

    for (int i = 0; i < fill_count; i++) {
        printf("Car %td needs filling\n", fill[i] - cars + 1);
    }

    printf("%d cars need filling\n", fill_count);

    return 0;
}
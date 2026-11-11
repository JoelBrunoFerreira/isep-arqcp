#include <stdio.h>
#include "asm.h"

#define NCARS 5

int main(void) {

    unsigned int cars[NCARS]={0xFFFFFFFF,0xFFFAFFFA,0x00000000,0xFCFDEFAB,0xFFFFFFFF};
    unsigned int *fill[NCARS]; // Array of pointers to store cars that need filling


    /**
     * Test low_pressure function for each car and print the results
     
    for (int i = 0; i < NCARS; i++) {
        int result = low_pressure(&cars[i]);
        if (result) {
            printf("Car %d has low pressure\n", i + 1);
        } else {
            printf("Car %d has normal pressure\n", i + 1);
        }
    }
    */

    int fill_count = check_tires(cars, NCARS, fill); // Call the function to check tires and get the count of cars needing filling

    for (int i = 0; i < fill_count; i++) {
        printf("Car %td needs filling\n", fill[i] - cars + 1);
    }

    printf("%d cars need filling\n", fill_count);
    
    return 0;
}
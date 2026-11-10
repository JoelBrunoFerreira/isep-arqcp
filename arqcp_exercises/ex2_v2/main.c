#include <stdio.h>
#include "asm.h"

#define NROBOTS 5

int main(void) {

    unsigned long long robots[NROBOTS] = {
        0x0000005000300010ULL,
        0x0000005000100040ULL,
        0x00010064000F0005ULL,
        0x0000000000200020ULL,
        0x0000006400320000ULL
    };
    unsigned long long *ready[NROBOTS];


    // Call the function to check robots and get the count of robots ready to travel
    int ready_count = check_robots(robots, NROBOTS, ready); 

    printf("Number of robots ready to travel: %d\n", ready_count);

    return 0;
}

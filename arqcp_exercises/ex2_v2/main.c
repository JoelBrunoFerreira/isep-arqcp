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

    /*
    // Test the can_travel function for each robot
    for (int i = 0; i < NROBOTS; i++) {
        if (can_travel(&robots[i])) {
            printf("Robot %d can travel.\n", i+1);
        } else {
            printf("Robot %d cannot travel.\n", i+1);
        }
    }
    */
    
    // Call the function to check robots and get the count of robots ready to travel
    int ready_count = check_robots(robots, NROBOTS, ready);
    for (int i = 0; i < ready_count; i++) {
        printf("Robot %d is ready to travel.\n", (int)(ready[i] - robots) + 1);
    }

    return 0;
}

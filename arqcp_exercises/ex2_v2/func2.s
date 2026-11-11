.section .text
    .global check_robots

check_robots:
    # int check_robots(unsigned long long *robots, int n, unsigned long long **ready);
    # a0 = pointer to the first robot's data
    # a1 = number of robots (n)
    # a2 = pointer to the output array (ready)
    # ===========================================

    # Prologue
    # ===========================================
    addi sp, sp, -32 # Allocate stack space for saved registers
    sw ra, 28(sp) # Save return address
    sw s0, 24(sp) # Save s0
    sw s1, 20(sp) # Save s1
    sw s2, 16(sp) # Save s2
    sw s3, 12(sp) # Save s3
    # ===========================================

    mv s0, a0 # Move the first argument (pointer to robot data) to s0
    mv s1, a1 # Move the second argument (number of robots) to s1
    mv s2, a2 # Move the third argument (pointer to output array) to s2
    li s3, 0  # count = 0

.Lcheck_robots_loop:
    bge zero, s1, .Lcheck_robots_done # Stop when n <= 0

    mv a0, s0 # Move the pointer to the current robot data to a0
    call can_travel 
    beqz a0, .Lcheck_robots_next # If the robot is not ready to travel (a0 == 0), skip to the next robot

    sw s0, 0(s2) # Store the robot's address in the output array
    addi s2, s2, 4 # Advance to the next fill slot in the output array
    addi s3, s3, 1 # Increment the count of ready robots (count++)

.Lcheck_robots_next:
    addi s0, s0, 8 # Advance to the next robot (each robot data is 8 bytes)
    addi s1, s1, -1 # Decrement the number of robots left to check
    j .Lcheck_robots_loop

.Lcheck_robots_done:
    mv a0, s3 # Move the number of ready robots to the return register (return count)

    # Epilogue
    # ===========================================
    lw s3, 12(sp) # Restore s3
    lw s2, 16(sp) # Restore s2
    lw s1, 20(sp) # Restore s1
    lw s0, 24(sp) # Restore s0
    lw ra, 28(sp) # Restore return address
    addi sp, sp, 32 # Deallocate stack space
    ret

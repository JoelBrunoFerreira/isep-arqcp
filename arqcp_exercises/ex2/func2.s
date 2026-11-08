.section .text
	.globl check_tires

check_tires:
	addi sp, sp, -32 # Allocate stack space for saved registers
	sw ra, 28(sp) # Save return address
	sw s0, 24(sp) # Save s0
	sw s1, 20(sp) # Save s1
	sw s2, 16(sp) # Save s2
	sw s3, 12(sp) # Save s3
	sw s4, 8(sp) # Save s4

	mv s0, a0 # Move the first argument (pointer to tire data) to s0
	mv s1, a1 # Move the second argument (number of tires) to s1
	mv s2, a2 # Move the third argument (pointer to output array) to s2
	li s3, 0  # count = 0

.Lcheck_tires_loop:
    bge  zero, s1, .Lcheck_tires_done # Stop when n <= 0

    mv   a0, s0
    call low_pressure
    beqz a0, .Lcheck_tires_next

    sw   s0, 0(s2)     # Store the car's address
    addi s2, s2, 4     # Advance to the next fill slot
    addi s3, s3, 1     # Increment the count of tires that need filling (count++)

.Lcheck_tires_next:
    addi s0, s0, 4     # Advance to the next car
    addi s1, s1, -1
    j    .Lcheck_tires_loop

.Lcheck_tires_done:
	mv a0, s3 # Move the number of tires that need filling to the return register (return count)
	lw s4, 8(sp)  # Restore s4
	lw s3, 12(sp) # Restore s3
	lw s2, 16(sp) # Restore s2
	lw s1, 20(sp) # Restore s1
	lw s0, 24(sp) # Restore s0
	lw ra, 28(sp) # Restore return address
	addi sp, sp, 32 # Deallocate stack space
	ret
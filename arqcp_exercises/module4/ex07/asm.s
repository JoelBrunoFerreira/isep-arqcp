.section .data

.section .bss

.section .text
	.global count_even
count_even:
	addi    sp, sp, -20          # Reserve stack space
	sw      ra, 16(sp)           # Save return address
	sw      s0, 12(sp)           # Save s0
	sw      s1, 8(sp)            # Save s1

	mv      s0, a0               # s0 = pointer to vector
	mv      s1, a1               # s1 = n (array size)
	li      a1, 0                # a1 = count of even numbers
	li      t0, 0                # t0 = index

loop:
	beq     t0, s1, end_loop     # If index equals n, end loop
	lh      a3, 0(s0)            # Load halfword from vector
	andi    a3, a3, 1            # Check if even (LSB is 0)
	beq     a3, zero, even       # If even number found
	j       skip_even            # Skip incrementing count

even:
	addi    a1, a1, 1            # Increment count of even numbers

skip_even:
	addi    s0, s0, 2            # Move to next halfword in vector
	addi    t0, t0, 1            # Increment index
	j       loop                 # Repeat loop

end_loop:
	mv      a0, a1               # Return count of even numbers
	lw      ra, 16(sp)           # Restore return address
	lw      s0, 12(sp)           # Restore s0
	lw      s1, 8(sp)            # Restore s1
	addi    sp, sp, 20           # Deallocate stack space
	ret

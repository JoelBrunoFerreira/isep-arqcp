.section .data

.section .bss

.section .text
	.global test_different
test_different:
	addi    sp, sp, -16          # Reserve stack space
	sw      ra, 12(sp)           # Save return address
	sw      s0, 8(sp)            # Save s0

	mv      s0, a0               # s0 = pointer to first string
	mv      t0, a1               # t0 = pointer to second string
loop:
	lb      a0, 0(s0)            # Load byte from first string
	lb      a1, 0(t0)            # Load byte from second string
	bne     a0, a1, different    # If bytes differ, strings are different
	beq     a0, zero, equal      # If end of string reached, strings are equal
	addi    s0, s0, 1            # Move to next byte in first string
	addi    t0, t0, 1            # Move to next byte in second string
	j       loop                 # Repeat loop
different:
	li      a0, 1                # Strings are different
	lw      ra, 12(sp)           # Restore return address
	lw      s0, 8(sp)            # Restore s0
	addi    sp, sp, 16           # Deallocate stack space
	ret
equal:
	li      a0, 0                # Strings are equal
	lw      ra, 12(sp)           # Restore return address
	lw      s0, 8(sp)            # Restore s0
	addi    sp, sp, 16           # Deallocate stack space
	ret

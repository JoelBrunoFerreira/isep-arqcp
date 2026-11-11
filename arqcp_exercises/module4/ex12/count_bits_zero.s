.section .data

.section .bss

.section .text
	.global count_bits_zero
count_bits_zero:
	li      t0, 0          # t0 will hold the count of zero bits
	li      t1, 32         # We will check 32 bits
count_loop:
	beq     t1, zero, end_count  # If we have checked all bits, exit loop
	and     t2, a0, 1      # Isolate the least significant bit
	beqz    t2, increment_count  # If the bit is 0, increment count
	j       next_bit
increment_count:
	addi    t0, t0, 1      # Increment zero bit count
next_bit:
	srli    a0, a0, 1      # Shift right to check the next bit
	addi    t1, t1, -1     # Decrement bit counter
	j       count_loop
end_count:
	mv      a0, t0         # Move the count to a0 for return
	ret

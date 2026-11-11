.section .data

.section .bss

.section .text
	.global calc
calc:
	# a0 = a
	# a1 = &b (pointer to b)
	# a2 = c

	li t0, 4          # t0 = 4
	mul t1, a0, t0    # t1 = a * 4
	lw t0, 0(a1)      # t0 = *b (load value at address a1)
	add t1, t1, t0    # t1 = a * 4 + *b  (z)

	li t2, 6          # t2 = 6
	sub t3, a2, t2    # t3 = c - 6

	mul a0, t3, t1    # a0 = (c - 6) * z
	ret

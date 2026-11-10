.section .data

.section .bss

.section .text
    .global vec_sum 
vec_sum:
    # a0 = ptr (pointer to array of ints)
    # a1 = num (number of elements)

    beq a1, zero, end      # if (num == 0) jump to end
    li t0, 0               # t0 = sum = 0

loop:
    lw t1, 0(a0)           # Load int from array
    add t0, t0, t1         # sum += loaded int

    addi a0, a0, 4         # Move pointer to next int (4 bytes)
    addi a1, a1, -1        # Decrement counter
    bne a1, zero, loop     # if (counter != 0) jump to loop

end:
    mv a0, t0              # Move sum to a0 for return
    ret

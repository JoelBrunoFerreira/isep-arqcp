.section .data

.section .bss

.section .text
    .global vec_add_three 
vec_add_three:
    # a0 = ptr (pointer to array of shorts)
    # a1 = num (number of elements)
    
    beq a1, zero, end      # if (num == 0) jump to end

loop:
    lh t0, 0(a0)           # Load short from array
    addi t0, t0, 3         # Add 3 to the loaded short
    sh t0, 0(a0)           # Store the modified short back
    
    addi a0, a0, 2         # Move pointer to next short (2 bytes)
    addi a1, a1, -1        # Decrement counter
    bne a1, zero, loop     # if (counter != 0) jump to loop

end:
    ret


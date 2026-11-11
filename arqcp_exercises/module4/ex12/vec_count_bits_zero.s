.section .data

.section .bss

.section .text
    .global vec_count_bits_zero
vec_count_bits_zero:
    addi sp, sp, -20  # Allocate stack space
    sw   ra, 16(sp)   # Save return address
    sw   s0, 12(sp)   # Save s0
    sw   s1, 8(sp)    # Save s1
    sw   s2, 4(sp)    # Save s2
    sw   s3, 0(sp)    # Save s3

    mv   s1, a0        # ptr
    mv   s2, a1        # num
    li   s0, 0         # total
    li   s3, 0         # i

loop:
    bge  s3, s2, done  # if i >= num, done
    lw   a0, 0(s1)     # load vec[i]
    call count_bits_zero  # call count_bits_zero
    add  s0, s0, a0    # total += result
    addi s1, s1, 4     # ptr++
    addi s3, s3, 1     # i++
    j    loop

done:
    mv   a0, s0       # move total to a0 for return
    lw   s3, 0(sp)    # Restore s3
    lw   s2, 4(sp)    # Restore s2
    lw   s1, 8(sp)    # Restore s1
    lw   s0, 12(sp)   # Restore s0
    lw   ra, 16(sp)   # Restore return address
    addi sp, sp, 20   # Deallocate stack space
    ret

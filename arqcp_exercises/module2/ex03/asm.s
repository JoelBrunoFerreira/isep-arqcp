.section .data
    .equ CONST_VAL, 20

.section .bss

.section .text
    .global sum3 
sum3:
    addi a0, a0, -CONST_VAL  # a0 = a0 - CONST_VAL
    li t0, CONST_VAL         # Load CONST_VAL into t0
    sub a1, t0, a1           # a1 = CONST_VAL - a1

    li t1, 2                 # Load value 2 into t1
    mul a0, a0, t1           # a0 = a0 * 2
    add a0, a0, a1           # a0 = (a0 - 20) + (20 - a1)
    ret

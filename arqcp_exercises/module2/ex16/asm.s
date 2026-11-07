.section .data

.section .bss

.section .text
    .global steps
steps:
    li t0, 3
    mv a1, a0
    li t1, 4

    mul a0, a0, t0
    addi a0, a0, 6
    div a0, a0, t0
    addi a0, a0, 12
    sub a0, a0, a1
    sub a0, a0, t1

    ret

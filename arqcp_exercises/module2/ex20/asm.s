.section .data
    .equ CODE_10, 10
    .equ CODE_11, 11
    .equ CODE_12, 12

.section .bss

.section .text
    .global new_salary
new_salary:
    # a0: current salary
    # a1: code
    li t0, CODE_10
    li t1, CODE_11
    li t2, CODE_12

    beq a1, t0, increase_500
    beq a1, t1, increase_400
    beq a1, t2, increase_300
    addi a0, a0, 250
    ret

increase_500:
    addi a0, a0, 500
    ret
increase_400:
    addi a0, a0, 400
    ret
increase_300:
    addi a0, a0, 300
    ret

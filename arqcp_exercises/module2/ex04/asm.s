.section .data

.section .bss

.section .text
    .global three_halves
three_halves:
    li t0, 3           # t0 = 3
    mul a0, a0, t0     # a0 = 3 * x
    li t1, 2           # t1 = 2
    div a0, a0, t1     # a0 = (3 * x) / 2
    ret

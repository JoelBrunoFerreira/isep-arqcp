.section .data

.section .bss

.section .text
    .global get_area
get_area:
    add a0, a0, a1
    li t0, 2
    div a0, a0, t0
    mul a0, a0, a2
    ret

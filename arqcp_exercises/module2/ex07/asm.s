.section .data

.section .bss

.section .text
    .global my_remainder
my_remainder:
    add a0, a0, a1   # a0 = x + y
    rem a0, a0, a2   # a0 = (x + y) % z
    ret

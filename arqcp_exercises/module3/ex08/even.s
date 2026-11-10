.section .data

.section .bss

.section .text
    .global test_even 
test_even:
    # test if x is even
    # a0 = x
    andi a0, a0, 1    # a0 = x & 1
    xori a0, a0, 1    # inverte: par->1, ímpar->0
    ret
    
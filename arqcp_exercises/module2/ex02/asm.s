.section .data

.section .bss

.section .text
    .global sum2  
sum2:
    add a0, a0, a0   # a0 = x + x
    add a0, a0, a1   # a0 = (2*x) + y
    ret

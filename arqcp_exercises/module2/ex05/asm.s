.section .data

.section .bss

.section .text
    .global parallel 
parallel:
    mul t0, a0, a1   # t0 = x * y
    add t1, a0, a1   # t1 = x + y
    div a0, t0, t1   # a0 = (x * y) / (x + y)
    ret
    
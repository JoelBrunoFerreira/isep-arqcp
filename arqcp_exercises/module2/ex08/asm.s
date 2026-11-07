.section .data

.section .bss

.section .text
    .global is_multiple
is_multiple:
    rem a0, a0, a1     # a0 = x % y
    li t0, 0           # t0 = 0
    beq a0, t0, multiple  # if a0 == 0, jump to multiple
    li a0, 0           # return 0 (false)  
    ret

multiple:
    li a0, 1           # return 1 (true)
    ret

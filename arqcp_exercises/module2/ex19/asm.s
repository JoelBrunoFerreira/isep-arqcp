.section .data

.section .bss

.section .text
    .global check_num
check_num:
    li t0, 2             # t0 = 2
    rem t2, a0, t0       # t2 = n % 2

    beq a0, x0, zero     # if n == 0, jump to zero
    beq t2, x0, even     # if t2 == 0, jump to even
    bne t2, x0, odd      # if t2 != 0, jump to odd
    ret

even:
    blt a0, x0, negative_even  # if n < 0, jump to negative_even
    li a0, 3
    ret

negative_even:
    li a0, 1
    ret

odd:
    blt a0, x0, negative_odd   # if n < 0, jump to negative_odd
    li a0, 4
    ret   

negative_odd:
    li a0, 2
    ret

zero:
    li a0, 0
    ret

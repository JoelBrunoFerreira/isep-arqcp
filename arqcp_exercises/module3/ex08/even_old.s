.section .data

.section .bss

.section .text
    .global test_even 
test_even:
    # test if x is even
    # a0 = x

    li t0, 2          # load immediate 2 into t0
    rem t1, a0, t0    # t1 = x % 2
    beqz t1, is_even     # if t1 == 0, x is even
    li a0, 0          # return 0 (false)
    ret
is_even:
    li a0, 1          # return 1 (true)
    ret

.section .data
    .equ TO_INCREASE, 4
    .equ TO_DECREASE, 3

.section .bss

.section .text
    .global needed_time
needed_time:
    li t0, TO_INCREASE
    li t1, TO_DECREASE
    # a0 = current temperature
    # a1 = desired temperature
    beq a0, a1, end_needed_time
    blt a0, a1, increase_temp
    sub t2, a0, a1          # t2 = current - desired
    mul a0, t2, t1          # a0 = t2 * TO_DECREASE
    ret

end_needed_time:
    li a0, 0
    ret    

increase_temp:
    sub t2, a1, a0          # t2 = desired - current
    mul a0, t2, t0          # a0 = t2 * TO_INCREASE
    ret

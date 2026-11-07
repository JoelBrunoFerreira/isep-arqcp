.section .data

.section .bss

.section .text
    .global time_sec
time_sec:
    li t0, 3600          # t0 = 3600 = seconds in an hour
    mul t1, a0, t0       # t1 = hour * 3600
    li t0, 60            # t0 = 60 = seconds in a minute
    mul t2, a1, t0       # t2 = min * 60
    add t3, t1, t2       # t3 = (hour * 3600) + (min * 60)
    add a0, t3, a2       # a0 = (hour * 3600) + (min * 60) + sec
    ret

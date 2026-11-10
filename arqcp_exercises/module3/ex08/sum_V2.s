.section .data

.section .bss

.section .text
    .global vec_sum_even

vec_sum_even:
    addi sp, sp, -16
    sw   ra, 12(sp)
    sw   s0, 8(sp)
    sw   s1, 4(sp)
    sw   s2, 0(sp)

    mv   s0, a0          # ptr
    mv   s1, a1          # num
    li   t0, 0           # sum
    li   t1, 0           # i

loop:
    bge  t1, s1, done
    lw   s2, 0(s0)       # guarda elemento em s2 (SAFE)

    mv   a0, s2
    call test_even       # a0 = 1 se par

    beqz a0, skip_add
    add  t0, t0, s2

skip_add:
    addi s0, s0, 4
    addi t1, t1, 1
    j    loop

done:
    mv   a0, t0

    lw   s2, 0(sp)
    lw   s1, 4(sp)
    lw   s0, 8(sp)
    lw   ra, 12(sp)
    addi sp, sp, 16
    ret

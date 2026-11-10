.section .data

.section .bss

.section .text
    .global vec_sum_even
    # int vec_sum_even(int* ptr, int num)
    # a0 = ptr
    # a1 = num
    # return a0 = sum of even elements
vec_sum_even:
    addi sp, sp, -16
    sw   ra, 12(sp)
    sw   s0, 8(sp)
    sw   s1, 4(sp)

    mv   s0, a0          # s0 = ptr (preservado)
    mv   s1, a1          # s1 = num (preservado)

    li   t0, 0           # t0 = sum
    li   t1, 0           # t1 = i

loop:
    bge  t1, s1, done    # if i >= num -> done

    lw   t2, 0(s0)       # t2 = *ptr

    # chamar test_even(t2)
    mv   a0, t2
    call test_even       # a0 = 1 se par, 0 se ímpar

    beqz a0, skip_add    # se impar, não soma
    add  t0, t0, t2      # se par, soma

skip_add:
    addi s0, s0, 4       # ptr++
    addi t1, t1, 1       # i++
    j    loop

done:
    mv   a0, t0          # return sum

    lw   s1, 4(sp)
    lw   s0, 8(sp)
    lw   ra, 12(sp)
    addi sp, sp, 16
    ret

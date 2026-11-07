.section .data
    .equ A, 3
    .equ B, 4

.section .bss

.section .text
    .global sigma
sigma:
    li t0, A          # t0 = A
    li t1, B          # t1 = B
    mul t2, t0, t0    # t2 = A * A
    mul t3, t2, t0    # t3 = A * A * A = A^3
    li t4, 1          # t4 = 1
    mv a1, a0         # a1 = n
    li a3, 0          # a3 = somatório inicializado em 0

    bne a1, t4, compute_sigma  # If n != 1, jump to compute_sigma
    div a0, t3, t1             # a0 = A^3 / B
    ret

compute_sigma:
    beq a1, t4, end_loop   # If n == 1, jump to end_loop
    mul t5, a1, a1    # t5 = n * n
    mul t6, t5, t3    # t6 = n^2 * A^3
    div a4, t6, t1    # a4 = (n^2 * A^3) / B
    add a3, a3, a4    # a3 = somatório + a4
    mv a0, a3         # Move o somatório para a0
    sub a1, a1, t4    # a1 = n - 1
    j compute_sigma
    ret
end_loop:
    div a6, t3, t1    # a6 = A^3 / B
    add a3, a3, a6    # a3 = somatório + a6
    mv a0, a3         # Move o somatório para a0
    ret

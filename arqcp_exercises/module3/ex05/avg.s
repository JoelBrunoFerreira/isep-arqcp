.section .data

.section .bss

.section .text
    .global vec_avg

    # int vec_avg(int* ptr, short num)
    # a0 = ptr
    # a1 = num
vec_avg:
    # Prologue (precisamos porque vamos fazer call -> ra vai ser alterado)
    addi sp, sp, -12
    sw   ra, 8(sp)        # salvar ra 
    sw   a1, 4(sp)        # guardar num (porque a1 é caller-saved)

    # call vec_sum(ptr, num)
    call vec_sum          # retorna sum em a0

    # recuperar num
    lw   t0, 4(sp)        # t0 = num

    # evitar divisão por zero
    beq  t0, zero, avg_zero

    div  a0, a0, t0       # a0 = sum / num

    # Epilogue
    lw   ra, 8(sp)        # recuperar ra
    addi sp, sp, 12       # restaurar sp
    ret

avg_zero:
    li   a0, 0
    lw   ra, 8(sp)
    addi sp, sp, 12
    ret

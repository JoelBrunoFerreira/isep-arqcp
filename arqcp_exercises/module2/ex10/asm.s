.section .data

.section .bss

.section .text
    .global big_sum
big_sum:
    # Assumindo que:
    # a1:a0 contém o primeiro número long long (a1 = upper bits, a0 = lower bits)
    # a3:a2 contém o segundo número long long (a3 = upper bits, a2 = lower bits)
    # O resultado será armazenado em a1:a0
    # sltu (Set Less Than Unsigned) é usado para detectar o carry -
    # O sltu compara se o resultado é menor que um dos operandos, o que só acontece se houve overflow na soma.

    add a0, a0, a2    # Soma os 32 bits menos significativos - (numeros mais à direita)
    sltu t0, a0, a2   # Verifica se houve carry (t0 = 1 se houve carry, 0 caso contrário)
    add a1, a1, a3    # Soma os 32 bits mais significativos - (numeros mais à esquerda)
    add a1, a1, t0    # Adiciona o carry à parte alta se necessário
    ret

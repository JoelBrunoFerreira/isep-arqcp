.section .data

.section .bss

.section .text
    .global six_packs
six_packs:
    li t0, 6        # Load immediate 6 into t0
    rem a1, a0, t0  # Remainder of num / 6 in a1

    beq a1, zero, exact_pack  # If remainder is 0, jump to exact_pack
    div a0, a0, t0  # Quotient of num / 6 in a0
    addi a0, a0, 1  # Otherwise, add 1 to the quotient
    ret

exact_pack:
    div a0, a0, t0  # Quotient of num / 6 in a0
    ret

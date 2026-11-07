.section .data

.section .bss

.section .text
    .global in_order
in_order:
    blt a0, a1, not_in_order  # If a0 < a1, jump to not_in_order
    blt a1, a2, not_in_order  # If a1 < a2, jump to not_in_order
    li a0, 1                   # If a0 > a1 > a2, return 1
    ret

not_in_order:
    li a0, 0                   # If not in order, return 0
    ret

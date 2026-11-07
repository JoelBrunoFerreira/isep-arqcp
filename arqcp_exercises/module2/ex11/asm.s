.section .data

.section .bss

.section .text
    .global is_greater
is_greater:
    beq a0, a1, equal             # If a0 == a1, jump to equal
    blt a0, a1, not_greater       # If a0 < a1, jump to not_greater
    li a0, 1                      # a0 > a1, return 1
    ret

equal:
    li a0, -1
    ret

not_greater:
    li a0, 0
    ret

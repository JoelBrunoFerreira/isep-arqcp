.section .data

.section .bss

.section .text
    .global five_count
five_count:
  mv t0, a0         # t0 = ptr
  li t1, 0          # t1 = current count of '5's
  li t2, 53         # '5' in ASCII

1:  lbu a1, 0(t0)   # load byte at ptr
  beq a1, zero, 2f  # if byte == '\0', end loop
  beq a1, t2, 3f    # if byte == '5', increment count
  addi t0, t0, 1    # move to next byte
  j 1b 

3:  addi t1, t1, 1  # increment count
  addi t0, t0, 1    # move to next byte
  j 1b

2:  mv a0, t1       # move count to a0
  ret

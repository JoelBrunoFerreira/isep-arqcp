.section .data
    # array
    .global array_a
array_a:
    .word 10 , 15 , 20 , 25 , 30 , 35 , 40 , 45 , 50 , 55 , 60 # initialize array_a with 11 integers
    
    # string
    .global string_a
string_a:
    .asciz "Hello, World!" # stores the string plus the terminating 0

.section .bss
    # array
    .comm array_e, 6*2 # reserve space for 6 elements of 2 bytes each (short)

    # string
    .comm string_e, 20 # reserve space for a string of 20 bytes

.section .text
    .global tenth_element 
tenth_element:
    # Accessing the 10th element of array_a
    la a0, array_a      # load address of array_a into a0
    lw a0, 36(a0)       # load the 10th element (index 9, offset 9*4=36) into a0
    ret

    .global fifth_char
fifth_char:
    # Accessing the 5th character of string_a
    la t0, string_a     # load address of string_a into t0
    lbu a0, 4(t0)       # load byte unsigned at offset 4 into a0
    ret
    
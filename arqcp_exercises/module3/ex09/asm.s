.section .data

.section .bss

.section .text
    .global vec_search 
    # int* vec_search(int* ptr, int num, int x);
    # ptr -> a0
    # num -> a1
    # x -> a2
vec_search:
    li t0, 0              # i = 0
loop:
    beqz a1, not_found    # if num == 0, return
    lw t1, 0(a0)          # load vec[i] into t1
    beq t1, a2, found     # if vec[i] == x, found
    addi a0, a0, 4        # ptr++
    addi a1, a1, -1       # i--
    j loop                # repeat loop
found:
    mv a0, a0             # return ptr (address of found element)  
    ret
not_found:
    li a0, 0              # return NULL (0)
    ret

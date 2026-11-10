.section .data

.section .bss

.section .text
    .global str_cat
    # void str_cat(char* ptr1, char* ptr2, char* ptr3);
    # ptr1: first string = a0
    # ptr2: second string = a1
    # ptr3: destination string = a2
str_cat:
    # Copy first string from ptr1 to ptr3
copy_first:
    lb t0, 0(a0)          # Load byte from ptr1
    beq t0, zero, copy_second # If null terminator, go to copy second string
    sb t0, 0(a2)          # Store byte to ptr3
    addi a0, a0, 1        # Move to next byte in ptr1
    addi a2, a2, 1        # Move to next byte in ptr3
    j copy_first          # Repeat   
    ret
    # Copy second string from ptr2 to ptr3
copy_second:
    lb t0, 0(a1)          # Load byte from ptr2
    beq t0, zero, end_str_cat # If null terminator, end
    sb t0, 0(a2)          # Store byte to ptr3
    addi a1, a1, 1        # Move to next byte in ptr2
    addi a2, a2, 1        # Move to next byte in ptr3
    j copy_second         # Repeat
    ret
end_str_cat:
    sb zero, 0(a2)        # Null terminate the concatenated string
    ret

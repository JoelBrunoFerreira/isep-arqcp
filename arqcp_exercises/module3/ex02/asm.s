.section .text
.global str_copy_roman

# void str_copy_roman(char* ptr1, char* ptr2)
# a0 = ptr1 (source string)
# a1 = ptr2 (destination string)
str_copy_roman:
    # Loop through each character in source string
loop:
    # Load character from source string
    lbu t0, 0(a0)           # t0 = *ptr1
    
    # Check if we've reached the null terminator
    beq t0, zero, end       # if (t0 == '\0') go to end
    
    # Check if character is 'u' (ASCII 117)         
    li t1, 117              # t1 = 'u'
    bne t0, t1, copy_char   # if (t0 != 'u') goto copy_char
    
    # Replace 'u' with 'v'
    li t0, 118              # t0 = 'v' (ASCII 118)
    
copy_char:
    # Store character to destination string
    sb t0, 0(a1)            # *ptr2 = t0
    
    # Move to next character
    addi a0, a0, 1          # ptr1++
    addi a1, a1, 1          # ptr2++
    
    # Continue loop
    j loop
    
end:
    # Null-terminate the destination string
    sb zero, 0(a1)          # *ptr2 = '\0'
    
    # Return
    ret


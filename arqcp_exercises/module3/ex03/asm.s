.section .data

.section .bss

.section .text
    .global str_copy_roman2 

    # void str_copy_roman(char* ptr1, char* ptr2)
    # a0 = ptr1 (source string)
    # a1 = ptr2 (destination string)

str_copy_roman2:
    # Loop through each character in source string
loop:
    # Load character from source string
    lbu t0, 0(a0)           # t0 = *ptr1

    # Check if we've reached the null terminator
    beq t0, zero, end       # if (t0 == '\0) go to end

    # Check if character is 'u' (ASCII 117)
    li t1, 117               # t1 = 'u'
    beq t0, t1, replace_u    # if (t0 == 'u') goto replace_u

    # Check if character is 'U' (ASCII 85)
    li t1, 85                # t1 = 'U'
    beq t0, t1, replace_U    # if (t0 == 'U') goto replace_U

    # Not 'u' or 'U', continue to copy
    j copy_char

replace_u:
    # Replace 'u' with 'v'
    li t0, 118               # t0 = 'v' (ASCII 118)
    j copy_char

replace_U:
    # Replace 'U' with 'V'
    li t0, 86                # t0 = 'V' (ASCII 86)

copy_char:
    # Store character to destination string 
    sb t0, 0(a1)             # *ptr2 = t0
    # Move to next character
    addi a0, a0, 1           # ptr1++
    addi a1, a1, 1           # ptr2++
    # Continue loop
    j loop
end:
    # Null-terminate the destination string
    sb zero, 0(a1)           # *ptr2 = '\0'
    # Return
    ret

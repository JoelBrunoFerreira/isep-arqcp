# ===============================================================
# Data section : initialized variables
# ===============================================================
.section .data
    .equ LINUX_SYS_CALL, 0x80    # define a constant (example)
    .equ CONST_VAL, 42           # another constant

# NUL-terminated strings
# ---------------------------------------------------------------
my_string:                         # variable identifier (my_string)
    .asciz "My string"             # NUL-terminated string
msg_nl:                            # another example string
    .asciz "Another string\n"      # NUL-terminated string

# Small data types
# ---------------------------------------------------------------
byte_val:
    .byte 0x12, 0x34, -1          # sequence of bytes (signed/unsigned)
half_val:
    .half 0x1234, 0xFFFF          # 16-bit values
word_val:
    .word 0x11223344, 100, CONST_VAL  # 32-bit words (integers)

# An initialized array of words
# ---------------------------------------------------------------
int_array:
    .word 1, 2, 3, 4, 5
    .align 2                     # align next data to 4 bytes (2^2)
    .equ int_array_count, 5      # helper constant (assembler expression)

# Pointer (word-sized) to a string
# ---------------------------------------------------------------
ptr_to_string:
    .word my_string

# Floating point example (optional; depends on toolchain/target)
# ---------------------------------------------------------------
float_val:
    .float 3.14



# ===============================================================
# BSS section : uninitialized storage
# ===============================================================
.section .bss
    .comm buffer, 10000 # global array of 10 000 bytes
    .lcomm buffer2, 500 # local array of 500 bytes (module local)



# ===============================================================
# Text section : code
# ===============================================================
.section .text
    .global function_name_here  # make ‘function_name_here ‘ visible to the linker

function_name_here: # entry point of the function
    # function code goes here
    ret

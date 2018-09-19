############################################################
# This assembly program is a part of a larger C program that reads a file and
# stores all the words in an array. The one assembly function decapitalizes all
# the words in the file so that only the first character of each word is left
# capitalized
# Author: Elisabeth Henderson
# Date: November 17, 2017
############################################################
    .file   "function.s"
    .intel_syntax noprefix
    .text

# ===============================================================
#    mylower
#    Takes an array of words and decapitalizes all but the first character
#    of each word
#    Inputs: In rdi, the array of words
#            In rsi, the number of words in the array
#    Outputs: None
#    Returns: None
#    Author: Elisabeth Henderson
# =============================================================== 
    .global mylower
    .type mylower, @function
mylower:
    push    rbp             # push rbp
    mov     rbp, rsp        # movs rsp into rbp
    xor     r9, r9          # 0 out r9
    xor     r10, r10        # 0 out r10
    xor     r11, r11        # 0 out r11
    xor     rax, rax        # 0 out rax
    inc     r10             # increment r10 to get past the first center
    inc     r11             # increment r11 to ensure it stays inline with r10

inner:
    cmp     r11, offset 20  # campare r11 to 20, which is the max number of
                            # characters in a word
    jnb     next            # if r11 is not below, jump to next
    inc     r11             # increment r11
    mov     al, BYTE PTR[rdi+r10] # move the character at rdi+r10 to al 
                                  # for comparison
    cmp     al, offset 0    # compare that character to 0 (null)
    je      skip            # if equal just to skip to skip that character
    add     al, offset 32   # if it is not equal to null, add 32 to the 
                            # character to lowercase it
    mov     [rdi+r10], al   # move the changed character back into the array
    inc     r10             # increment r10
    jmp     inner           # jump back to inner to loop

skip:
    inc     r10             # increment r10 to skip the null charater
    jmp     inner           # jump back to innder to loop

next:
    cmp     r9, rsi         # compare r9 to the number of words in the list
    jnb     bail            # jump to bail if it is not below
    inc     r9              # increment r9 
    xor     r11,r11         # clear out r11
    inc     r10             # increment r10 to get back first character of the
                            # next word
    inc     r11             # increment r11 to ensure it stays inline with r10
    jmp     inner           # jump back to inner

bail:
    pop     rbp             # pop rbp
    ret                     # return

    .section    .note>GNU-stack,"",@progbits

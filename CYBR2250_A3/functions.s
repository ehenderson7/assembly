############################################################
# This assembly program is a part of a larger C program that takes in a four
# by four table, in sense, and used it to encrypt characters. This is done
# through bit-shifting. This file contains two of the methods. The first is
# encrypt, which takes in a character and a table and encrypts and
# return the character. The second is rotate, which takes a table and rotates
# it. 
# Author: Elisabeth Henderson
# Date: November 3, 2017
############################################################

	.file	"functions.s"
	.intel_syntax noprefix
	.text
/* ===============================================================
    encrypt
    Takes in two inputs, the character to encrypt and the table by which it
    should be done. Encryptes the character based on the table passed and
    returns an encrypted character.
    Inputs: In edi, the character to encrypt
            In rsi, the table to encrypt with
    Outputs: None
    Returns: In eax, the encrypted character
    Author: Elisabeth Henderson
 =============================================================== */
    .globl	encrypt
	.type	encrypt, @function
encrypt:
	push	rbp
	mov	    rbp, rsp
    sub     rsp, 20 # make space for local variables 
    mov     DWORD PTR[rsp], offset 0 # local variable 1 for data storage
    mov     DWORD PTR[rsp+4], offset 128 # local variable 2 for scaling
    mov     DWORD PTR[rsp+8], offset 64 # local variable 3 for scaling
    mov     DWORD PTR[rsp+12], offset # local variable for the final int
    xor     r8, r8      # used for addressing the array   
    xor     r9, r9      # used for counting inner loop
    xor     r10, r10    # used for counting outter loop
    xor     edx, edx    # used for swapping bits
    xor     ebx, ebx    # used for swapping bits
    xor     rax, rax    # used for returning an int
    xor     al, al      # used for comparison
    mov     ebx, edi    # move the int passed into ebx

inner:
    cmp     r9, offset 4        # compare r9 (inner loop counter) to 3
    jnb     outter              # break out of inner, to outter, if not below
    inc     r9                  # increment r9
    mov     al, BYTE PTR[rsi+r8]# mov chr at current position in table to al
    cmp     al, offset 83       # compare chr to S (ascii 83)
    je      S                   # jump to S if equal
    jmp     N                   # otherwise jump to N

outter: 
    cmp     r10, offset 4       # compare r10 (outter loop counter) to 3      
    jnb     bail                # bail if not below
    inc     r10                 # increment r10
    sub     r8, offset 15       # subtract 15 from r8 to go to the next colunm
    xor     r9, r9              # 0 out r9
    add     DWORD PTR[rsp+12], ebx  # add swapped bits to the final int to save 
    mov     ebx, edi            # mov the int passed into ebx for the next swap
    shr     DWORD PTR[rsp+4], offset 2  # shift scale1 right by 2
    shr     DWORD PTR[rsp+8], offset 2  # shift scale2 right by 2
    jmp     inner               # jump back to inner

S:
    add     r8, offset 4        # add 4 to r8 so it can do to next row after
    mov     edx, ebx            # move ebx into edx to prepare for the swaps
    and     edx, [rsp+4]        # and edx with the scale, to get the bit
    shr     edx, 1              # shift edx right by 1
    mov     DWORD PTR[rsp], ebx # store ebx into local variable 1
    mov     ebx, edx            # move edx into ebx for storage 
    mov     edx, DWORD PTR[rsp] # move the stored value into edx for swapping
    and     edx, [rsp+8]        # and edx with the scale to get the bit
    shl     edx, 1              # shift edx left by 1
    add     ebx, edx            # add the two shifted bits together to swap
    jmp     inner               # jump back to inner

N:
    add     r8, offset 4        # add 4 to r8 so it can go to the next row
    mov     edx, ebx            # move ebx into edx to prepare for the nonswaps
    and     edx, [rsp+4]        # and edx with the scale, to get the bit
    mov     DWORD PTR[rsp], ebx # store ebx into local variable 1
    mov     ebx, edx            # move edx into ebx for storage
    mov     edx, DWORD PTR[rsp] # move the stored value into edx for swapping
    and     edx, [rsp+8]        # and edx with the scale to get the bit
    add     ebx, edx            # add the two to get the non-shifted bits
    jmp     inner               # jump back to inner

bail:
    mov     eax, DWORD PTR[rsp+12]  # move the final int to eax to be returned
    add     rsp, 20                 # add back to the stack
    pop	    rbp                     # pop rbp
	ret                             # return

/* ===============================================================
    rotate
    Takes in one input, the table to be rotated. Then rotates the table
    90 degress counterclockwise stores that rotation back into table
    and returns nothing
    Inputs: In rsi, the table to rotate
    Outputs: None
    Returns: None
    Author: Elisabeth Henderson
================================================================== */

    .globl	rotate
	.type	rotate, @function
rotate:
	push	rbp
	mov	    rbp, rsp
    
    sub     rsp, offset 16 # make space for the temp table
    
    # each group of moves serves to store the value of the passed table into
    # al and then move the value stored in al into the temp table 
    # the numbers are mismatched so that the temp table is rotated 90 in 
    # comparison to the passed table
    mov     al, BYTE PTR[rdi+3]
    mov     [rsp], al
    
    mov     al, BYTE PTR[rdi+7]
    mov     [rsp+1], al
    
    mov     al, BYTE PTR[rdi+11]
    mov     [rsp+2], al
    
    mov     al, BYTE PTR[rdi+15]
    mov     [rsp+3], al

    mov     al, BYTE PTR[rdi+2]
    mov     [rsp+4], al

    mov     al, BYTE PTR[rdi+6]
    mov     [rsp+5], al

    mov     al, BYTE PTR[rdi+10]
    mov     [rsp+6], al

    mov     al, BYTE PTR[rdi+14]
    mov     [rsp+7], al

    mov     al, BYTE PTR[rdi+1]
    mov     [rsp+8], al

    mov     al, BYTE PTR[rdi+5]
    mov     [rsp+9], al

    mov     al, BYTE PTR[rdi+9]
    mov     [rsp+10], al

    mov     al, BYTE PTR[rdi+13]
    mov     [rsp+11], al

    mov     al, BYTE PTR[rdi]
    mov     [rsp+12], al

    mov     al, BYTE PTR[rdi+4]
    mov     [rsp+13], al

    mov     al, BYTE PTR[rdi+8]
    mov     [rsp+14], al

    mov     al, BYTE PTR[rdi+12]
    mov     [rsp+15], al
    
    mov     rsi, rsp        # move temp table into rsi for memcpy call
    mov     rdx, offset 16  # move number of bits (16) into rdx for memcpy
    call    memcpy          # call memcpy to copy temp to table
    add     rsp, offset 16  # add back allocated memory
	pop	    rbp             # pop rbp
	ret                     # return 

	.section	.note.GNU-stack,"",@progbits

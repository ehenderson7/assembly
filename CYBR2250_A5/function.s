############################################################
# This assembly program is a part of a larger C program that reads a file and
# processes it line by line to find all mathematical solutions to the possible
# numbers given. The one assembly function takes in a number and determines 
# how many segments are in that number.
# Author: Elisabeth Henderson
# Date: December 8, 2017
############################################################
    .file "function.s"
    .intel_syntax noprefix
    .text

    .global segments
    .type segments, @function

# ===============================================================
#    segments
#    Takes in a number and determines how many segments would be lit up on
#    a calculator by that number
#    Inputs: In edi, the number
#    Outputs: None
#    Returns: In eax, the number of segments
#    Author: Elisabeth Henderson
# ===============================================================
segments:
    push    rbp         # push rbp
    mov     rbp, rsp    # move rsp into rbp
    sub     rsp, 12     # make space for 3 local int variables
    mov     DWORD PTR[rsp], offset 0    # 0 out the first variable
                                        # stores the total segments 
    mov     DWORD PTR[rsp+4], offset 0  # 0 out the second variable
                                        # is the loop counter
    mov     DWORD PTR[rsp+8], offset 0  # 0 out the last variable
                                        # stores a number for "if" statments
    test    edi, 0x80000000             # test edi to see if it is negative
    jz      iffs                        # if not jump to the "if" statements
    neg     edi                         # otherwise negate edi 
    mov     DWORD PTR[rsp], offset 1    # and add one into the total segments
                                        # for the representation of the (-)

# these "if" statments test the size of the variable and set the power of ten
# accordingly to ensure no extra 0s are added to the number during the loop
iffs:
    cmp     edi, offset 9999
    ja      tensth
    
    cmp     edi, offset 999     # compare the number to 999
    ja      thous               # if it is above, it is in the thousands, so
                                # jump there
    cmp     edi, offset 99      # compare the number to 99
    ja      huns                # if it is above, it is in the hundreds, so
                                # jump there
    cmp     edi, offset 9       # compare the number to 9
    ja      tens                # if it is above, it is in the tens, jump there
    mov     DWORD PTR[rsp+4], offset 1  # otherwise it is in the ones, so move
                                        # a one into the "power" variable 
    jmp     loop                        # jump to the loop

tensth:
    mov     DWORD PTR[rsp+4], offset 10000
    jmp     loop

thous:
    mov     DWORD PTR[rsp+4], offset 1000   # the number is in the thousand so
    jmp     loop                            #start the power at 1000

huns:
    mov     DWORD PTR[rsp+4], offset 100    # the number is in the hundreds so
                                            # start the power at 100
    jmp     loop                            # jump to the loop

tens:
    mov     DWORD PTR[rsp+4], offset 10     # the number is in the tens so
                                            # start the power at 10
    jmp     loop                            # jump to the loop

loop:
    cmp     DWORD PTR[rsp+4], offset 0  # compare the "power" to 0
    jna     bail                        # if it is below, jump to bail
    
    # division to deal with the number
    mov     ebx, DWORD PTR[rsp+4]       # move the power into ebx for division
    mov     eax, edi                    # move the number into eax
    cdq                                 # sign-extend eax for division
    idiv    ebx                         # divide eax by ebx
    mov     DWORD PTR[rsp+8], eax       # store the whole part of the division
                                        # for comparison next
    mov     edi, edx                    # store the remainder in edi for the 
                                        # next round

    # division to deal with the "power"
    mov     ebx, offset 10              # move 10 into ebx
    mov     eax, DWORD PTR[rsp+4]       # move the current power into eax
    cdq                                 # sign-extend eax
    idiv    ebx                         # divide eax by ebx
    mov     DWORD PTR[rsp+4], eax       # store the result for the next round
    
    # simulated switch/if statements to calculate the number of segments
    # each jump statement will jump to a block of assembly code that adds that 
    # number to the total segments and then jump back to the loop
    cmp     DWORD PTR[rsp+8], offset 0  # if the number is 0 jump to psix
    je      psix                        
    cmp     DWORD PTR[rsp+8], offset 6  # if the number is 6 jump to psix
    je      psix                       
    cmp     DWORD PTR[rsp+8], offset 9  # if the number is 9 jump to psix
    je      psix

    cmp     DWORD PTR[rsp+8], offset 1  # if the number is 1 jump to ptwo
    je      ptwo

    cmp     DWORD PTR[rsp+8], offset 2  # if the number is 2 jump to pfive
    je      pfive
    cmp     DWORD PTR[rsp+8], offset 3  # if the number is 3 jump to pfive 
    je      pfive
    cmp     DWORD PTR[rsp+8], offset 5  # if the number is 5 jump to pfive
    je      pfive

    cmp     DWORD PTR[rsp+8], offset 4  # if the number is 4 jump to pfour
    je      pfour

    cmp     DWORD PTR[rsp+8], offset 7  # if the number is 7 jump to pthree
    je      pthree

    cmp     DWORD PTR[rsp+8], offset 8  # if the number is 8 jump to pseven
    je      pseven

psix:
    add     DWORD PTR[rsp], offset 6    # add six to the total segments
    jmp     loop                        # jump back to the loop

ptwo:
    add     DWORD PTR[rsp], offset 2    # add two to the total segments
    jmp     loop                        # jump back to the loop

pfive:
    add     DWORD PTR[rsp], offset 5    # add five to the total segments
    jmp     loop                        # jump back to the loop

pfour:
    add     DWORD PTR[rsp], offset 4    # add four to the total segments
    jmp     loop                        # jump back to the loop

pthree:
    add     DWORD PTR[rsp], offset 3    # add three to the total segments
    jmp     loop                        # jump back to the loop

pseven:
    add     DWORD PTR[rsp], offset 7    # add seven to the total segments
    jmp     loop                        # jump back to the loop

bail:
    mov     eax, DWORD PTR[rsp] # move the total segments to eax to return
    add     rsp, offset 12      # add back to the stack
    pop     rbp                 # pop rbp   
    ret                         # return

    .section .note>GUN-stack,"",@progbits

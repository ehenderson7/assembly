############################################################
# Memcpy notes
# This is what GCC will generate with no optimization.
############################################################

	.file	"memcpy.c"
	.intel_syntax noprefix
	.text
	.globl	my_memcpy
	.type	my_memcpy, @function
my_memcpy:
.LFB0:
	push	rbp
	mov	rbp, rsp
	mov	QWORD PTR [rbp-24], rdi		# Remember that RDI is parameter 1 (Dest)
	mov	QWORD PTR [rbp-32], rsi		# RSI is parameter 2 (Source)
	mov	QWORD PTR [rbp-40], rdx		# RDX is parameter 3 (N)
	mov	rax, QWORD PTR [rbp-24]
	mov	QWORD PTR [rbp-8], rax		# void *save = dest
	jmp	.L2				# Jump down to test "while( n-- )"
.L3:
	mov	rax, QWORD PTR [rbp-32]		# Get the pointer Source
	movzx	edx, BYTE PTR [rax]		# character = *ptr (withzero extend)
	mov	rax, QWORD PTR [rbp-24]		# Get the pointer Dest
	mov	BYTE PTR [rax], dl		# *ptr = character
	add	QWORD PTR [rbp-24], 1		# Dest++
	add	QWORD PTR [rbp-32], 1		# Source++
.L2:
	cmp	QWORD PTR [rbp-40], 0		# Compare N to zero
	setne	al				# Sets AL to 1 if not zero result
	sub	QWORD PTR [rbp-40], 1		# n--
	test	al, al				# If not zero, more to do, so
	jne	.L3				# Jump up and move another byte
	mov	rax, QWORD PTR [rbp-8]		# return( save )
	pop	rbp
	ret

.LFE0:
	.size	my_memcpy, .-my_memcpy
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

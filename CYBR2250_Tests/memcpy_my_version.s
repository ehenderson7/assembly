############################################################
# Memcpy notes
# So this is what I came up with - better.
############################################################

	.file	"memcpy.c"
	.intel_syntax noprefix
	.text
	.globl	my_memcpy
	.type	my_memcpy, @function
my_memcpy:
	push	rbp
	mov	rbp, rsp
	sub	rsp, 8				# Space for variable "save"
	mov	QWORD PTR [rsp], rdi		# save = dest
top:	cmp	rdx, 0				# Compare N to zero
	jz	go				# If it is, leave.
	dec	rdx				# N--
	mov	al, BYTE PTR[ rsi ]		# character = *source
	mov	BYTE PTR[ rdi ], al		# *dest = character
	inc	rsi				# source++
	inc	rdi				# dest++
	jmp	top
go:	mov	rax, QWORD PTR [rbp-8]		# return( save )
	add	rsp, 8				# Release variable "save"
	pop	rbp
	ret

.LFE0:
	.size	my_memcpy, .-my_memcpy
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

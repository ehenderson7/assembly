############################################################
#
# This is the code for:
#
# unsigned work( unsigned l, char op, unsigned r );
#
# So remember:
#
#	RDI will have argument 1, "l"  (but really EDI)
#	RSI will have argument 2, "op" (but really ESI)
#	RDX will ahve argument 3, "r"  (but really EDX)
#
# Also take a look at this:
# https://stackoverflow.com/questions/6212665/why-is-eax-zeroed-before-a-call-to-printf
#
# Below is the code for:
#
# void has42( unsigned *p, unsigned N );
#
#	RDI will have argument 1, address of the array
#	RSI will have argument 2, number of elements (but really ESI)
#
############################################################

	.file	"work.s"
	.intel_syntax noprefix

	.data
shoot:	.asciz	"There's something terribly wrong!\n"

	.text
	.globl	work
	.type	work, @function
work:
	push	rbp
	mov	rbp, rsp
	sub	rsp, 8				# No need for locals, but this is where they'd go.

	and	rsi, offset 0x0000007f		# Just to make sure it is only a char
	cmp	sil, 'A'			# SIL is low byte of RSI
	je	andit
	cmp	sil, 'O'
	je	orit
	cmp	sil, 'X'
	je	xorit

	mov	rdi, offset shoot		# This shouldn't happen.
	mov	eax,0				# See above. Needed for variable parameter list.
	call	printf				# So we will complain.
	xor	eax, eax			# Return a zero.
	
bail:	add	rsp, 8				# Release variable "save"
	pop	rbp
	ret

andit:	mov	eax, edi
	and	eax, edx
	jmp	bail

orit:	mov	eax, edi
	or	eax, edx
	jmp	bail

xorit:	mov	eax, edi
	xor	eax, edx
	jmp	bail
	
.LFE0:
	.size	work, .-work
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits


############################################################
#
# Disclaimer: This code is intentionally not very good. We have plenty
# of registers, so there is no need for a local variable, for
# example. But we're showing how it works really.
#	
############################################################

	.text
	.globl	has42
	.type	has42, @function

has42:	push	rbp
	mov	rbp, rsp
	sub	rsp, 4			# This is not very efficient but we want
	xor	eax, eax		# to show a local variable "i" that will
	mov	dword ptr [rbp-4], eax	# count from 0 up to N

top:	mov	eax, dword ptr [rbp-4]	# Get I
	cmp	eax, esi		# Second parameter is N
	jnb	out			# Jump if not below (>=)

	# OK here's some array stuff.
	# Right now EAX has "I" and
	# RDI will be the address of the array

	mov	eax, dword ptr [rdi+rax*4]
	cmp	eax, offset 42
	je	foundit
	
	inc	dword ptr [rbp-4]	# I++
	jmp	top

out:	xor	eax, eax		# Didn't find it, return 0
foundit: add	rsp, 4			# Clean up locals
	pop	rbp
	ret
	
	.size	has42, .-has42
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

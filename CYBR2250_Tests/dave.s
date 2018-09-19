	########################################
	# This is some assembly language to
	# go play around with a global variable.
	# I added some cool comments too...
	########################################

	.file	"dave.s"				# In the debugger it will tell what file the code came from.
	.intel_syntax noprefix				# We want intel syntax and not AT&T syntax for our class.
	.text						# This says "the following is code, not data"

	.globl	dave			# THis is a function that is visible all over
	.type	dave, @function		# Oh by the way, it is a function.
	
dave:
	push	rbp					# Covered later.
	mov	rbp, rsp				# Covered later.

	# Ok here's the guts of the function.
	mov	cx, offset 5
	xor	rax,rax
again:	
	add	eax, dword ptr [rdi]
	add	eax, dword ptr [rsi]
	dec	cx
	jnz	again
	
	# End of the guts of the function.
	
	pop	rbp					# Covered later.
	ret						# RETurn from the function back to the caller.

.LFE0:
	.size	dave, .-dave
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

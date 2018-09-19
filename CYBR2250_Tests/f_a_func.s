	########################################
	# This is some assembly language to
	# go play around with a global variable.
	# I added some cool comments too...
	########################################

	.file	"f_a_func.s"				# In the debugger it will tell what file the code came from.

	.intel_syntax noprefix				# We want intel syntax and not AT&T syntax for our class.

	.text						# This says "the following is code, not data"

	.globl	far_away_function			# THis is a function that is visible all over
	.type	far_away_function, @function		# Oh by the way, it is a function.
	
far_away_function:
.LFB0:
	.cfi_startproc					# Anything that starts with CFI just leave.
	push	rbp					# Covered later.
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	mov	rbp, rsp				# Covered later.
	.cfi_def_cfa_register 6

	# Ok here's the guts of the function.
	
	mov	eax, DWORD PTR [global_variable]
	sal	eax, 2					# global_variable <<= 2
	add	eax, 4					# global_variable += 4
	mov	DWORD PTR [global_variable], eax

	# End of the guts of the function.
	
	pop	rbp					# Covered later.
	.cfi_def_cfa 7, 8
	ret						# RETurn from the function back to the caller.
	.cfi_endproc

	# These things tell the debugger about the code. Just leave 'em.
	
.LFE0:
	.size	far_away_function, .-far_away_function
	.ident	"GCC: (Ubuntu/Linaro 4.6.3-1ubuntu5) 4.6.3"
	.section	.note.GNU-stack,"",@progbits

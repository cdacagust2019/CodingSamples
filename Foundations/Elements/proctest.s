	.intel_syntax noprefix

	.include "console.i"

	.text

askn:	.asciz	"Enter a positive integer: "
ans:	.asciz	"G.C.D = "

_entry:
	mov	rbp, rsp
	sub	rsp, 12
	
	Prompt	askn
	GetInt	[rbp+8]
	Prompt	askn
	GetInt	[rbp+12]

	mov	eax, [rbp+8]
	mov	edx, [rbp+12]
	call	_GCD
	mov	[rbp+16], eax

	Prompt	ans
	PutInt	[rbp+16]
	PutEoL

	mov	rsp, rbp
	ret

	.global	_entry

	.end



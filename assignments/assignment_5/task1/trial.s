	.file	"trial.c"
	.text
	.globl	buffer
	.bss
	.type	buffer, @object
	.size	buffer, 7
buffer:
	.zero	7
	.section	.rodata
.LC0:
	.string	"%d\n%d\n"
.LC1:
	.string	"%d\n"
.LC2:
	.string	"%s"
.LC3:
	.string	"%c %c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	leaq	buffer(%rip), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, %rdx
	movl	$7, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movb	$97, buffer(%rip)
	movb	$0, 1+buffer(%rip)
	leaq	buffer(%rip), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, %rdx
	movl	$7, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movb	$98, 1+buffer(%rip)
	leaq	buffer(%rip), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movb	$0, 2+buffer(%rip)
	leaq	buffer(%rip), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movb	$0, 1+buffer(%rip)
	leaq	buffer(%rip), %rax
	movq	%rax, %rdi
	call	strlen@PLT
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movb	$99, 2+buffer(%rip)
	leaq	buffer(%rip), %rax
	movq	%rax, %rsi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movzbl	2+buffer(%rip), %eax
	movsbl	%al, %edx
	movzbl	buffer(%rip), %eax
	movsbl	%al, %eax
	movl	%eax, %esi
	leaq	.LC3(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Debian 11.2.0-20) 11.2.0"
	.section	.note.GNU-stack,"",@progbits

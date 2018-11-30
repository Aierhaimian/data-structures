	.file	"heapSort.cpp"
	.local	_ZStL8__ioinit
	.comm	_ZStL8__ioinit,1,1
	.text
	.align 2
	.globl	_ZN4HeapC2Ei
	.type	_ZN4HeapC2Ei, @function
_ZN4HeapC2Ei:
.LFB1119:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movl	%esi, -12(%rbp)
	movq	-8(%rbp), %rax
	movl	-12(%rbp), %edx
	movl	%edx, 8(%rax)
	movq	-8(%rbp), %rax
	movl	8(%rax), %eax
	cltq
	movabsq	$2287828610704211968, %rdx
	cmpq	%rdx, %rax
	ja	.L2
	salq	$2, %rax
	jmp	.L3
.L2:
	movq	$-1, %rax
.L3:
	movq	%rax, %rdi
	call	_Znam
	movq	%rax, %rdx
	movq	-8(%rbp), %rax
	movq	%rdx, (%rax)
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1119:
	.size	_ZN4HeapC2Ei, .-_ZN4HeapC2Ei
	.globl	_ZN4HeapC1Ei
	.set	_ZN4HeapC1Ei,_ZN4HeapC2Ei
	.section	.rodata
.LC0:
	.string	"open error!"
	.text
	.align 2
	.globl	_ZN4Heap9readArrayENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.type	_ZN4Heap9readArrayENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, @function
_ZN4Heap9readArrayENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE:
.LFB1121:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1121
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$984, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -984(%rbp)
	movq	%rsi, -992(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	movq	-992(%rbp), %rax
	movq	%rax, %rdi
.LEHB0:
	call	_ZNKSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE5c_strEv
	movq	%rax, %rcx
	leaq	-544(%rbp), %rax
	movl	$8, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEEC1EPKcSt13_Ios_Openmode
.LEHE0:
	leaq	-544(%rbp), %rax
	addq	$256, %rax
	movq	%rax, %rdi
.LEHB1:
	call	_ZNKSt9basic_iosIcSt11char_traitsIcEEntEv
	testb	%al, %al
	je	.L5
	movl	$.LC0, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
.L5:
	leaq	-960(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1Ev
.LEHE1:
	leaq	-960(%rbp), %rdx
	leaq	-544(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB2:
	call	_ZSt7getlineIcSt11char_traitsIcESaIcEERSt13basic_istreamIT_T0_ES7_RNSt7__cxx1112basic_stringIS4_S5_T1_EE
	leaq	-960(%rbp), %rcx
	leaq	-928(%rbp), %rax
	movl	$8, %edx
	movq	%rcx, %rsi
	movq	%rax, %rdi
	call	_ZNSt7__cxx1119basic_istringstreamIcSt11char_traitsIcESaIcEEC1ERKNS_12basic_stringIcS2_S3_EESt13_Ios_Openmode
.LEHE2:
	movl	$0, -968(%rbp)
	leaq	-968(%rbp), %rdx
	leaq	-928(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB3:
	call	_ZNSirsERi
	movl	-968(%rbp), %edx
	movq	-984(%rbp), %rax
	movl	%edx, 8(%rax)
	movl	$1, -964(%rbp)
.L7:
	movl	-968(%rbp), %eax
	cmpl	%eax, -964(%rbp)
	jg	.L6
	movq	-984(%rbp), %rax
	movq	(%rax), %rax
	movl	-964(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rax, %rdx
	leaq	-928(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	_ZNSirsERi
	addl	$1, -964(%rbp)
	jmp	.L7
.L6:
	leaq	-544(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEE5closeEv
.LEHE3:
	leaq	-928(%rbp), %rax
	movq	%rax, %rdi
.LEHB4:
	call	_ZNSt7__cxx1119basic_istringstreamIcSt11char_traitsIcESaIcEED1Ev
.LEHE4:
	leaq	-960(%rbp), %rax
	movq	%rax, %rdi
.LEHB5:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
.LEHE5:
	leaq	-544(%rbp), %rax
	movq	%rax, %rdi
.LEHB6:
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev
.LEHE6:
	nop
	movq	-24(%rbp), %rax
	xorq	%fs:40, %rax
	je	.L11
	jmp	.L15
.L14:
	movq	%rax, %rbx
	leaq	-928(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1119basic_istringstreamIcSt11char_traitsIcESaIcEED1Ev
	jmp	.L9
.L13:
	movq	%rax, %rbx
.L9:
	leaq	-960(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	jmp	.L10
.L12:
	movq	%rax, %rbx
.L10:
	leaq	-544(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt14basic_ifstreamIcSt11char_traitsIcEED1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB7:
	call	_Unwind_Resume
.LEHE7:
.L15:
	call	__stack_chk_fail
.L11:
	addq	$984, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1121:
	.globl	__gxx_personality_v0
	.section	.gcc_except_table,"a",@progbits
.LLSDA1121:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1121-.LLSDACSB1121
.LLSDACSB1121:
	.uleb128 .LEHB0-.LFB1121
	.uleb128 .LEHE0-.LEHB0
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB1-.LFB1121
	.uleb128 .LEHE1-.LEHB1
	.uleb128 .L12-.LFB1121
	.uleb128 0
	.uleb128 .LEHB2-.LFB1121
	.uleb128 .LEHE2-.LEHB2
	.uleb128 .L13-.LFB1121
	.uleb128 0
	.uleb128 .LEHB3-.LFB1121
	.uleb128 .LEHE3-.LEHB3
	.uleb128 .L14-.LFB1121
	.uleb128 0
	.uleb128 .LEHB4-.LFB1121
	.uleb128 .LEHE4-.LEHB4
	.uleb128 .L13-.LFB1121
	.uleb128 0
	.uleb128 .LEHB5-.LFB1121
	.uleb128 .LEHE5-.LEHB5
	.uleb128 .L12-.LFB1121
	.uleb128 0
	.uleb128 .LEHB6-.LFB1121
	.uleb128 .LEHE6-.LEHB6
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB7-.LFB1121
	.uleb128 .LEHE7-.LEHB7
	.uleb128 0
	.uleb128 0
.LLSDACSE1121:
	.text
	.size	_ZN4Heap9readArrayENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE, .-_ZN4Heap9readArrayENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
	.section	.rodata
.LC1:
	.string	"\346\225\260\347\273\204\350\247\204\346\250\241\357\274\232"
.LC2:
	.string	"\346\225\260\347\273\204\345\205\203\347\264\240\357\274\232"
.LC3:
	.string	" "
	.text
	.align 2
	.globl	_ZN4Heap9showArrayEv
	.type	_ZN4Heap9showArrayEv, @function
_ZN4Heap9showArrayEv:
.LFB1122:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$40, %rsp
	.cfi_offset 3, -24
	movq	%rdi, -40(%rbp)
	movq	-40(%rbp), %rax
	movl	8(%rax), %ebx
	movl	$.LC1, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	%ebx, %esi
	movq	%rax, %rdi
	call	_ZNSolsEi
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	movl	$.LC2, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	movl	$1, -20(%rbp)
.L18:
	movq	-40(%rbp), %rax
	movl	8(%rax), %eax
	cmpl	-20(%rbp), %eax
	jl	.L17
	movq	-40(%rbp), %rax
	movq	(%rax), %rax
	movl	-20(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, %esi
	movl	$_ZSt4cout, %edi
	call	_ZNSolsEi
	movl	$.LC3, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	addl	$1, -20(%rbp)
	jmp	.L18
.L17:
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movl	$_ZSt4cout, %edi
	call	_ZNSolsEPFRSoS_E
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1122:
	.size	_ZN4Heap9showArrayEv, .-_ZN4Heap9showArrayEv
	.align 2
	.globl	_ZN4Heap11maxHeapLifeEii
	.type	_ZN4Heap11maxHeapLifeEii, @function
_ZN4Heap11maxHeapLifeEii:
.LFB1123:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	%edx, -32(%rbp)
	movl	-28(%rbp), %eax
	addl	%eax, %eax
	movl	%eax, -12(%rbp)
	movl	-28(%rbp), %eax
	addl	%eax, %eax
	addl	$1, %eax
	movl	%eax, -8(%rbp)
	movl	-28(%rbp), %eax
	movl	%eax, -16(%rbp)
	movl	-32(%rbp), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	cmpl	-28(%rbp), %eax
	jl	.L24
	movl	-12(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jg	.L21
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	-12(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	-16(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$2, %rcx
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jle	.L21
	movl	-12(%rbp), %eax
	movl	%eax, -16(%rbp)
.L21:
	movl	-8(%rbp), %eax
	cmpl	-32(%rbp), %eax
	jg	.L22
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %edx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	-16(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$2, %rcx
	addq	%rcx, %rax
	movl	(%rax), %eax
	cmpl	%eax, %edx
	jle	.L22
	movl	-8(%rbp), %eax
	movl	%eax, -16(%rbp)
.L22:
	movl	-16(%rbp), %eax
	cmpl	-28(%rbp), %eax
	je	.L24
	movl	$0, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	-28(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rdx, %rax
	movl	(%rax), %eax
	movl	%eax, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	-28(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rax, %rdx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	-16(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$2, %rcx
	addq	%rcx, %rax
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	-16(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	movl	%eax, (%rdx)
	movl	-32(%rbp), %edx
	movl	-16(%rbp), %ecx
	movq	-24(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	_ZN4Heap11maxHeapLifeEii
.L24:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1123:
	.size	_ZN4Heap11maxHeapLifeEii, .-_ZN4Heap11maxHeapLifeEii
	.align 2
	.globl	_ZN4Heap12buildMaxHeapEv
	.type	_ZN4Heap12buildMaxHeapEv, @function
_ZN4Heap12buildMaxHeapEv:
.LFB1124:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movl	8(%rax), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%edx, %eax
	sarl	%eax
	movl	%eax, -4(%rbp)
.L27:
	cmpl	$0, -4(%rbp)
	jle	.L28
	movq	-24(%rbp), %rax
	movl	8(%rax), %edx
	movl	-4(%rbp), %ecx
	movq	-24(%rbp), %rax
	movl	%ecx, %esi
	movq	%rax, %rdi
	call	_ZN4Heap11maxHeapLifeEii
	subl	$1, -4(%rbp)
	jmp	.L27
.L28:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1124:
	.size	_ZN4Heap12buildMaxHeapEv, .-_ZN4Heap12buildMaxHeapEv
	.align 2
	.globl	_ZN4Heap8heapSortEv
	.type	_ZN4Heap8heapSortEv, @function
_ZN4Heap8heapSortEv:
.LFB1125:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4Heap12buildMaxHeapEv
	movq	-24(%rbp), %rax
	movl	8(%rax), %eax
	movl	%eax, -8(%rbp)
.L31:
	cmpl	$1, -8(%rbp)
	jle	.L32
	movl	$0, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	4(%rax), %eax
	movl	%eax, -4(%rbp)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	leaq	4(%rax), %rdx
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	-8(%rbp), %ecx
	movslq	%ecx, %rcx
	salq	$2, %rcx
	addq	%rcx, %rax
	movl	(%rax), %eax
	movl	%eax, (%rdx)
	movq	-24(%rbp), %rax
	movq	(%rax), %rax
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	salq	$2, %rdx
	addq	%rax, %rdx
	movl	-4(%rbp), %eax
	movl	%eax, (%rdx)
	movl	-8(%rbp), %eax
	leal	-1(%rax), %edx
	movq	-24(%rbp), %rax
	movl	$1, %esi
	movq	%rax, %rdi
	call	_ZN4Heap11maxHeapLifeEii
	subl	$1, -8(%rbp)
	jmp	.L31
.L32:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1125:
	.size	_ZN4Heap8heapSortEv, .-_ZN4Heap8heapSortEv
	.align 2
	.globl	_ZN4HeapD2Ev
	.type	_ZN4HeapD2Ev, @function
_ZN4HeapD2Ev:
.LFB1127:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	testq	%rax, %rax
	je	.L35
	movq	-8(%rbp), %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	_ZdaPv
.L35:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1127:
	.size	_ZN4HeapD2Ev, .-_ZN4HeapD2Ev
	.globl	_ZN4HeapD1Ev
	.set	_ZN4HeapD1Ev,_ZN4HeapD2Ev
	.section	.rodata
.LC5:
	.string	"array.txt"
	.align 8
.LC6:
	.string	"\345\240\206\346\216\222\345\272\217\347\256\227\346\263\225\346\211\247\350\241\214\346\227\266\351\227\264\344\270\272\357\274\232"
.LC7:
	.string	"\345\276\256\347\247\222"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1129:
	.cfi_startproc
	.cfi_personality 0x3,__gxx_personality_v0
	.cfi_lsda 0x3,.LLSDA1129
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$136, %rsp
	.cfi_offset 3, -24
	movq	%fs:40, %rax
	movq	%rax, -24(%rbp)
	xorl	%eax, %eax
	pxor	%xmm0, %xmm0
	movss	%xmm0, -116(%rbp)
	leaq	-80(%rbp), %rax
	movl	$1000000, %esi
	movq	%rax, %rdi
.LEHB8:
	call	_ZN4HeapC1Ei
.LEHE8:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcEC1Ev
	leaq	-96(%rbp), %rdx
	leaq	-64(%rbp), %rax
	movl	$.LC5, %esi
	movq	%rax, %rdi
.LEHB9:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC1EPKcRKS3_
.LEHE9:
	leaq	-64(%rbp), %rdx
	leaq	-80(%rbp), %rax
	movq	%rdx, %rsi
	movq	%rax, %rdi
.LEHB10:
	call	_ZN4Heap9readArrayENSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE
.LEHE10:
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
.LEHB11:
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
.LEHE11:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
.LEHB12:
	call	_ZN4Heap9showArrayEv
	leaq	-112(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	gettimeofday
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4Heap8heapSortEv
	leaq	-96(%rbp), %rax
	movl	$0, %esi
	movq	%rax, %rdi
	call	gettimeofday
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4Heap9showArrayEv
	movq	-96(%rbp), %rdx
	movq	-112(%rbp), %rax
	subq	%rax, %rdx
	movq	%rdx, %rax
	imulq	$1000000, %rax, %rax
	movq	-88(%rbp), %rcx
	movq	-104(%rbp), %rdx
	subq	%rdx, %rcx
	movq	%rcx, %rdx
	addq	%rdx, %rax
	pxor	%xmm0, %xmm0
	cvtsi2ssq	%rax, %xmm0
	movss	%xmm0, -116(%rbp)
	movl	$.LC6, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movq	%rax, %rdx
	movl	-116(%rbp), %eax
	movl	%eax, -132(%rbp)
	movss	-132(%rbp), %xmm0
	movq	%rdx, %rdi
	call	_ZNSolsEf
	movl	$.LC7, %esi
	movq	%rax, %rdi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
.LEHE12:
	movl	$0, %ebx
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4HeapD1Ev
	movl	%ebx, %eax
	movq	-24(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L41
	jmp	.L45
.L43:
	movq	%rax, %rbx
	leaq	-64(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED1Ev
	jmp	.L39
.L42:
	movq	%rax, %rbx
.L39:
	leaq	-96(%rbp), %rax
	movq	%rax, %rdi
	call	_ZNSaIcED1Ev
	jmp	.L40
.L44:
	movq	%rax, %rbx
.L40:
	leaq	-80(%rbp), %rax
	movq	%rax, %rdi
	call	_ZN4HeapD1Ev
	movq	%rbx, %rax
	movq	%rax, %rdi
.LEHB13:
	call	_Unwind_Resume
.LEHE13:
.L45:
	call	__stack_chk_fail
.L41:
	addq	$136, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1129:
	.section	.gcc_except_table
.LLSDA1129:
	.byte	0xff
	.byte	0xff
	.byte	0x1
	.uleb128 .LLSDACSE1129-.LLSDACSB1129
.LLSDACSB1129:
	.uleb128 .LEHB8-.LFB1129
	.uleb128 .LEHE8-.LEHB8
	.uleb128 0
	.uleb128 0
	.uleb128 .LEHB9-.LFB1129
	.uleb128 .LEHE9-.LEHB9
	.uleb128 .L42-.LFB1129
	.uleb128 0
	.uleb128 .LEHB10-.LFB1129
	.uleb128 .LEHE10-.LEHB10
	.uleb128 .L43-.LFB1129
	.uleb128 0
	.uleb128 .LEHB11-.LFB1129
	.uleb128 .LEHE11-.LEHB11
	.uleb128 .L42-.LFB1129
	.uleb128 0
	.uleb128 .LEHB12-.LFB1129
	.uleb128 .LEHE12-.LEHB12
	.uleb128 .L44-.LFB1129
	.uleb128 0
	.uleb128 .LEHB13-.LFB1129
	.uleb128 .LEHE13-.LEHB13
	.uleb128 0
	.uleb128 0
.LLSDACSE1129:
	.text
	.size	main, .-main
	.type	_Z41__static_initialization_and_destruction_0ii, @function
_Z41__static_initialization_and_destruction_0ii:
.LFB1265:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	%edi, -4(%rbp)
	movl	%esi, -8(%rbp)
	cmpl	$1, -4(%rbp)
	jne	.L48
	cmpl	$65535, -8(%rbp)
	jne	.L48
	movl	$_ZStL8__ioinit, %edi
	call	_ZNSt8ios_base4InitC1Ev
	movl	$__dso_handle, %edx
	movl	$_ZStL8__ioinit, %esi
	movl	$_ZNSt8ios_base4InitD1Ev, %edi
	call	__cxa_atexit
.L48:
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1265:
	.size	_Z41__static_initialization_and_destruction_0ii, .-_Z41__static_initialization_and_destruction_0ii
	.type	_GLOBAL__sub_I__ZN4HeapC2Ei, @function
_GLOBAL__sub_I__ZN4HeapC2Ei:
.LFB1266:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$65535, %esi
	movl	$1, %edi
	call	_Z41__static_initialization_and_destruction_0ii
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1266:
	.size	_GLOBAL__sub_I__ZN4HeapC2Ei, .-_GLOBAL__sub_I__ZN4HeapC2Ei
	.section	.init_array,"aw"
	.align 8
	.quad	_GLOBAL__sub_I__ZN4HeapC2Ei
	.hidden	__dso_handle
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits


.text
.global start
.global d_28
.global d_30
.global func_258
.extern vector_el1
.extern vector_el2
.extern vector_el3

start:
	ldr	x1, =vector_el1
	msr	vbar_el1, x1
	ldr	x2, =vector_el2
	msr	vbar_el2, x2
	ldr	x3, =vector_el3
	msr	vbar_el3, x3
	mov	w3, #0x501
	msr	scr_el3, x3
	b		l_38

.align 3
d_28:
	.dword 0x80006920
d_30:
	.dword 0x80000000

l_38:
	mrs	x19, mpidr_el1
	ubfx	x19, x19, #0, #8
	cbnz	x19, l_8b4
	ldr	x0, #0x30
	add	x0, x0, #0xc10
	mov	sp, x0
	bl		func_264


func_258:
	ret


func_264:
	ret

l_8b4:


/*
.data
Data_80005024:
	.dword 0
*/

.bss
Data_80005028:
	.dword 0


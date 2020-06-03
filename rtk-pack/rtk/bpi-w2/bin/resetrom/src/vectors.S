
.global vector_el1
.global vector_el2
.global vector_el3

.align 11

vector_el1:
l_13800:
	b	l_13800
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
l_13880:
	b	l_13880
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
l_13900:
	b	l_13900
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
l_13980:
	b	l_13980
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
l_13a00:
	b	l_13a00
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
l_13a80:
	b	l_13a80
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
l_13b00:
	b	l_13b00
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
l_13b80:
	b	l_13b80
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
l_13c00:
	b	l_13c00
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
l_13c80:
	b	l_13c80
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
l_13d00:
	b	l_13d00
	nop
	nop
	nop
	nop
	nop
	nop
	nop

#if 0
	.align 7
   13d80:	14000000 	b	0x13d80
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   13e00:	14000000 	b	0x13e00
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   13e80:	14000000 	b	0x13e80
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   13f00:	14000000 	b	0x13f00
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   13f80:	14000000 	b	0x13f80
	nop
	nop
	nop
	nop
	nop
	nop
	nop
#endif

	.align 7
vector_el2:
l_14000:
	b	l_14000
	nop
	nop
	nop
	nop
	nop
	nop
	nop

#if 0
	.align 7
   14080:	14000000 	b	0x14080
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14100:	14000000 	b	0x14100
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14180:	14000000 	b	0x14180
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14200:	14000000 	b	0x14200
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14280:	14000000 	b	0x14280
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14300:	14000000 	b	0x14300
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14380:	14000000 	b	0x14380
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14400:	14000000 	b	0x14400
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14480:	14000000 	b	0x14480
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14500:	14000000 	b	0x14500
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14580:	14000000 	b	0x14580
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14600:	14000000 	b	0x14600
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14680:	14000000 	b	0x14680
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14700:	14000000 	b	0x14700
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14780:	14000000 	b	0x14780
	nop
	nop
	nop
	nop
	nop
	nop
	nop
#endif

	.align 7
vector_el3:
l_14800:
	b	l_14800
	nop
	nop
	nop
	nop
	nop
	nop
	nop

#if 0
	.align 7
   14880:	14000000 	b	0x14880
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14900:	14000000 	b	0x14900
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14980:	14000000 	b	0x14980
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14a00:	14000000 	b	0x14a00
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14a80:	14000000 	b	0x14a80
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14b00:	14000000 	b	0x14b00
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14b80:	14000000 	b	0x14b80
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14c00:	14000000 	b	0x14c00
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14c80:	14000000 	b	0x14c80
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14d00:	14000000 	b	0x14d00
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14d80:	14000000 	b	0x14d80
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14e00:	14000000 	b	0x14e00
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14e80:	14000000 	b	0x14e80
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14f00:	14000000 	b	0x14f00
	nop
	nop
	nop
	nop
	nop
	nop
	nop

	.align 7
   14f80:	14000000 	b	0x14f80
	nop
	nop
	nop
	nop
	nop
	nop
	nop
#endif

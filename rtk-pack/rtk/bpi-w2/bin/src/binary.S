;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.data
.globl resetrom
.globl resetrom_end
resetrom:
.word \
0x01020304,0x05060708,0x090a0b0c,0x0d0e0f10\


resetrom_end:
.word 0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.data
.globl mips_resetrom
.globl mips_resetrom_end
mips_resetrom:
.word \
0x11121314,0x15161718,0x191a1b1c,0x1d1e1f20\


mips_resetrom_end:
.word 0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.data
.globl hwsetting
.globl hwsetting_end
hwsetting:
.word \
0x11121314,0x15161718,0x191a1b1c,0x1d1e1f20\
,\
0x11121314,0x15161718,0x191a1b1c,0x1d1e1f20\


hwsetting_end:
.word 0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.data
.globl hasharray
.globl hasharray_end
hasharray:
.word \
0x11121314,0x15161718,0x191a1b1c,0x1d1e1f20\


hasharray_end:
.word 0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.data
.globl signature
.globl signature_end
signature:
.word \
0x11121314,0x15161718,0x191a1b1c,0x1d1e1f20\


signature_end:
.word 0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.data
.globl bootcode2_boot_hasharray
.globl bootcode2_boot_hasharray_end
bootcode2_boot_hasharray:
.word \

bootcode2_boot_hasharray_end:
.word 0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.data
.globl linux_rescue_hasharray
.globl linux_rescue_hasharray_end
linux_rescue_hasharray:
.word \

linux_rescue_hasharray_end:
.word 0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.globl fsbl
.globl fsbl_end
fsbl:
.word \
0x11121314,0x15161718,0x191a1b1c,0x1d1e1f20\


fsbl_end:
.word 0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.globl fsbl_signature
.globl fsbl_signature_end
fsbl_signature:
.word \
0x11121314,0x15161718,0x191a1b1c,0x1d1e1f20\


fsbl_signature_end:
.word 0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.data
.globl fsbl_os
.globl fsbl_os_end
fsbl_os:
.word \


fsbl_os_end:
.word 0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.data
.globl fsbl_os_signature
.globl fsbl_os_signature_end
fsbl_os_signature:
.word \


fsbl_os_signature_end:
.word 0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.data
.globl bl31
.globl bl31_end
bl31:
.word \


bl31_end:
.word 0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.data
.globl bl31_signature
.globl bl31_signature_end
bl31_signature:
.word \


bl31_signature_end:
.word 0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.data
.globl rsa_pub
.globl rsa_pub_end
rsa_pub:
.word \


rsa_pub_end:
.word 0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;



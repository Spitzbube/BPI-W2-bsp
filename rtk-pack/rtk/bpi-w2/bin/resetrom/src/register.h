

#define CP15ISB	asm volatile ("ISB SY" : : : "memory")
#define CP15DSB	asm volatile ("DSB SY" : : : "memory")
#define CP15DMB	asm volatile ("DMB SY" : : : "memory")

#define REG32(reg)							*((volatile unsigned int*)(reg))
#define REG8(reg)							*((volatile unsigned char*)(reg))

#define SOFT_RESET1							0x98000000
#define SOFT_RESET2							0x98000004
#define CLOCK_ENABLE2						0x98000010
#define DREQ_MASK							0x9801a138

#define PWDN_CTRL							0x98000320
#define PWDN_CTRL2							0x98000324
#define PWDN_CTRL3							0x98000328
#define PWDN_CTRL4							0x9800032C

#define ISO_DUMMY1							0x98007054
#define ISO_DUMMY2							0x98007058
#define ISO_RESERVED_USE_1					0x98007078
#define ISO_MUXPAD0							0x98007310
#define ISO_U0SRR							0x98007888
#define ISO_SB2_0							0x98007F00


#define UART0_REG_BASE						0x98007800
#define UART1_REG_BASE						0x9801B200


#define INV_INTEN							0x9801A004

#define CP_OTP_LOAD							0x9801519c

#define SB2_CHIP_INFO						0x9801a204

#define SYS_muxpad0							0x98012600
#define SYS_muxpad1							0x98012604
#define EMMC_PFUNC_CR						0x98012610
#define EMMC_PFUNC_NF2						0x98012618

#define SB2_MUXPAD5							0x9801a914

#define SB2_SYNC							0x9801a020

#define MIS_UMSK_ISR						0x9801B008
#define MIS_TC0TVR							0x9801B500
#define MIS_TC0TVR_							(0x9801B500/4)
#define MIS_TC0CR							0x9801B518
#define MIS_TC0ICR							0x9801B524





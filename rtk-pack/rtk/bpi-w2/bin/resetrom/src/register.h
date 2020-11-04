

#define CP15ISB	asm volatile ("ISB SY" : : : "memory")
#define CP15DSB	asm volatile ("DSB SY" : : : "memory")
#define CP15DMB	asm volatile ("DMB SY" : : : "memory")

#define REG32(reg)							*((volatile unsigned int*)(reg))
#define REG8(reg)							*((volatile unsigned char*)(reg))

#define SOFT_RESET1							0x98000000
#define SOFT_RESET2							0x98000004
#define CLOCK_ENABLE2						0x98000010
#define DREQ_MASK							0x9801a138

#define PLL_EMMC1							0x980001F0

#define PWDN_CTRL							0x98000320
#define PWDN_CTRL2							0x98000324
#define PWDN_CTRL3							0x98000328
#define PWDN_CTRL4							0x9800032C

#define ISO_DUMMY1							0x98007054
#define ISO_DUMMY2							0x98007058
#define ISO_RESERVED_USE_1					0x98007078
#define ISO_MUXPAD0							0x98007310
#define ISO_COLD_RST9						0x98007678
#define ISO_U0SRR							0x98007888
#define ISO_SB2_0							0x98007F00


#define UART0_REG_BASE						0x98007800
#define UART1_REG_BASE						0x9801B200

#define INV_INTEN							0x9801A004

#define CP_OTP_LOAD							0x9801519c

#define SB2_CHIP_INFO						0x9801a204

#define EMMC_PAD_CTL						0x98012474

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

#define CTRL3								0x9804cf08
#define CTRL4								0x9804cf0c
#define SEC_CTRL1							0x9804cf80
#define SEC_CTRL3							0x9804cf84
#define SEC_CTRL4							0x9804cf88

#define MIS_GP1DIR							0x9801B104
#define MIS_GP1DATI							0x9801B124

#define MIS_TCWCR							0x9801B5B0
#define MIS_TCWTR							0x9801B5B4
#define MIS_TCWOV							0x9801B5BC

#define DUMMY_0								0x9801A600




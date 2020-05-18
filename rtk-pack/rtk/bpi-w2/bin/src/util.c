
#include "sysdefs.h"
#include "util.h"
#include "uart.h"
#include "uart_reg.h"
#include "iso_reg.h"


volatile        UARTREG         *UartReg = (UARTREG *) UARTREG_BASE_ADDRESS; //15AF568


void init_uart(void)
{
	unsigned int reg_val;
	unsigned int urMuxPad_val = 0x00555000;

	//1195, set ur0,ur1 pin mux, pin : 12~23
	reg_val = REG32(ISO_muxpad0) & ~(0x00fff000);
	REG32(ISO_muxpad0) = reg_val | urMuxPad_val;

	#ifdef ENABLE_UART_FUNC
	// init uart0
	REG32(U0LCR) = 0x90;
	#ifdef FPGA
	//REG32(U0RBR_THR_DLL) = 0x1b;  // 115200 baud (for FPGA 50MHz) 50*1000*1000/115200/16
	REG32(U0RBR_THR_DLL) = 0x12;    // 115200 baud (for FPGA 33MHz) 33*1000*1000/115200/16
	#else
	REG32(U0RBR_THR_DLL) = 0xe;             // 115200 baud (for ASIC 27MHz)
	#endif
	REG32(U0IER_DLH) = 0;
	REG32(U0LCR) = 0x3;                             // 8-N-1
	REG32(U0IIR_FCR) = 0xb7;
	REG32(U0IER_DLH) = 0;

	#if 0
	//init uart1
	REG32(U1LCR) = 0x90;
	#ifdef FPGA
	REG32(U1RBR_THR_DLL) = 0x12;    // 115200 baud (for FPGA 33MHz) 33*1000*1000/115200/16
	#else
	REG32(U1RBR_THR_DLL) = 0xf;             // 115200 baud (for ASIC 27MHz)
	#endif
	REG32(U1IER_DLH) = 0;
	REG32(U1LCR) = 0x3;                     // 8-N-1
	REG32(U1IIR_FCR) = 0xb7;
	REG32(U1IER_DLH) = 0;
	#endif
	#endif
}


void set_focus_uart(int currentUartPort)
{
	UartReg = (currentUartPort == 0) ? (UARTREG *)UART0_REG_BASE : (UARTREG *)UART1_REG_BASE;
}




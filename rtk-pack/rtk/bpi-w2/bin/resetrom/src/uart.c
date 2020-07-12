
#include "uart.h"


volatile UARTREG *UartReg = (UARTREG *) UARTREG_BASE_ADDRESS; //80005048
int Data_80005348[256];
int Data_80005dd4; //80005dd4


void init_uart(void)
{
	*((volatile unsigned int*)ISO_U0SRR) =
		*((volatile unsigned int*)ISO_U0SRR) | 0x07;

	func_c79c(100);

	*((volatile unsigned int*)ISO_MUXPAD0) =
		(*((volatile unsigned int*)ISO_MUXPAD0) & ~0x3C00) | 0x1400;

	*((volatile unsigned int*)U0LCR) = 0x90;
	*((volatile unsigned int*)U0RBR_THR_DLL) = 0x0F;
	*((volatile unsigned int*)U0IER_DLH) = 0;
	*((volatile unsigned int*)U0LCR) = 3;
	*((volatile unsigned int*)U0IIR_FCR) = 0xC7;
	*((volatile unsigned int*)U0IER_DLH) = 1;
}


/* 5da8 - complete */
void func_5da8(void)
{
	*((volatile unsigned int*)U0IIR_FCR) = 0x1;
	*((volatile unsigned int*)U0IIR_FCR) = 0x7;
}


/* 5dc4 - complete */
void func_5dc4(void)
{
	*((volatile unsigned int*)U0IIR_FCR) = 0xB7;
}


/* complete */
void set_focus_uart(int currentUartPort)
{
	UartReg = (currentUartPort == 0) ? (UARTREG *)UART0_REG_BASE : (UARTREG *)UART1_REG_BASE;
}


/* complete */
void serial_write(unsigned char  *p_param)
{
	while ((UartReg->UartLsr.Value & UARTINFO_TRANSMITTER_READY_MASK) != UARTINFO_TRANSMITTER_READY_MASK);

	if (Data_80005dd4 == 0)
	{
		UartReg->UartRbrTheDll.Value = *p_param;
	}
}


/* complete */
void prints(const char *ch)
{
	unsigned char ch8;

	while (*ch != '\0')
	{
		ch8 = *ch;
		if (*ch++ == '\n')
		{
			ch8 = 0x0d;
			serial_write((UINT8 *)&ch8);
			ch8 = 0x0a;
		}
		serial_write((UINT8 *) &ch8);
	}
}


/* complete */
void print_val(UINT32 val, UINT32 len)
{
	unsigned char ch;

	len--;
	do {
		ch = (val >> (len << 2)) & 0xf;
		ch += (ch < 0xa ? 0x30 : 0x37);
		serial_write(&ch);
	} while(len--);
}


/* complete */
void print_hex(unsigned int value)
{
	print_val(value, 8);
}


int serial_read(unsigned char  *p_param)
{
	if ((UartReg->UartLsr.Value & 1) != 1)
	{
		return 1;
	}

	*p_param = UartReg->UartRbrTheDll.Value;

	return 0;
}


/* 65b8 - todo */
void func_65b8(void)
{
	int r9;

	for (r9 = 0; r9 < 256; r9++)
	{
		Data_80005348[r9] = 42; //TODO
	}
}

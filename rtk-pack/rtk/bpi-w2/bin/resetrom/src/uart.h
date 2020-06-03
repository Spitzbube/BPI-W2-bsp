

#include "register.h"


typedef unsigned char UINT8;
typedef unsigned int UINT32;

#define U0RBR_THR_DLL						(UART0_REG_BASE + 0x0)
#define U0IER_DLH							(UART0_REG_BASE + 0x4)
#define U0IIR_FCR							(UART0_REG_BASE + 0x8)
#define U0LCR								(UART0_REG_BASE + 0xc)

#define UARTREG_BASE_ADDRESS 				UART0_REG_BASE

#define	UARTINFO_TEMT_MASK					0x40
#define	UARTINFO_THRE_MASK					0x20
#define UARTINFO_TRANSMITTER_READY_MASK		(UARTINFO_TEMT_MASK | UARTINFO_THRE_MASK)

typedef union _UARTREG_RBR_THR_DLL
{
    UINT32  Value;
    struct
    {
                                            //Register: UART_RBR_THR_DLL (0x1801_B200)
        UINT32  DLL: 8;             		//IO[7:0]: Divisor Latch LSB
        UINT32  Reserved: 24;               //IO[31:8]: Reserved

    } Fields0;

    struct
    {
                                            //Register: UART_RBR_THR_DLL (0x1801_B200)
        UINT32  RBD: 8;             		//IO[7:0]: Read: Receiver Buffer Data
        UINT32  Reserved: 24;               //IO[31:8]: Reserved

    } Fields1;

    struct
    {
                                            //Register: UART_RBR_THR_DLL (0x1801_B200)
        UINT32  THD: 8;             		//IO[7:0]: Write: Transmitter Holding Data
        UINT32  Reserved: 24;               //IO[31:8]: Reserved

    } Fields2;

} UARTREG_RBR_THR_DLL;


typedef union _UARTREG_LSR
{
    UINT32  Value;
    struct
    {
                                            //Register: UART_LSR (0x1801_B214)
        UINT32  DR: 1;             			//IO[0]: Data ready.
											//		 - Character mode: data ready in RBR
											//		 - FIFO mode: receiver FIFO is not empty

        UINT32	OE: 1;						//IO[1]: Overrun error.
        									//		 An overrun occurs when the receiver FIFO is
        									//		 full and the next character is completely received
        									//		 in the receiver shift register. An OE is indicated.
        									//		 The character in the shift register will be overwritten
        UINT32	PE: 1;						//IO[2]: Parity error
        UINT32	FE: 1;						//IO[3]: Framing error
        UINT32	BI: 1;						//IO[4]: Break interrupt indicator
        UINT32	THRE: 1;					//IO[5]: Transmitter holding register empty.
											//		 - Character mode: THR is empty.
											//		 - FIFO mode: transmitter FIFO is empty
        UINT32	TEMT: 1;					//IO[6]: Transmitter empty
											//		 - Character mode: both THR and TSR are empty.
											//		 - FIFO mode: both transmitter FIFO and TSR are empty
        UINT32	RFE: 1;						//IO[7]: Errors in receiver FIFO.
        									//		 At least one parity, framing and break error in the FIFO.
        UINT32  Reserved: 24;            	//IO[31:8]: Reserved
    } Fields;

} UARTREG_LSR;


typedef struct _UARTREG
{
	UARTREG_RBR_THR_DLL		UartRbrTheDll;	//0x1800_7800: UART_RBR_THR_DLL
#if 0
	UARTREG_IER_DLM			UartIerDlm;    	//0x1800_7804: UART_IER_DLM
	UARTREG_IIR_FCR			UartIirFcr;    	//0x1800_7808: UART_IIR_FCR
	UARTREG_LCR				UartLcr;       	//0x1800_780C: UART_LCR
	UARTREG_MCR				UartMcr;       	//0x1800_7810: UART_MCR
#else
	int fill_4[4]; //4
#endif
	UARTREG_LSR				UartLsr;       	//0x1800_7814: UART_LSR
#if 0
	UARTREG_MSR				UartMsr;       	//0x1800_7818: UART_MSR
	UARTREG_SCR				UartScr;       	//0x1800_781C: UART_SCR
#endif

} UARTREG;


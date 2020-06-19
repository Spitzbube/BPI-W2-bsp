
#include "uart.h"
#include "timer.h"


/* e500 - complete */
UINT32 InitTimer(unsigned int timerID, unsigned int dwInit)
{
	//Set The Initial Value
	REG32(MIS_TC0TVR+timerID*4) = dwInit;

	//Disable Interrupt
	REG32(MIS_TC0ICR+timerID*4) = TIMERINFO_INTERRUPT_DISABLE;

	//Disable Timer
	REG32(MIS_TC0CR+timerID*4) = TIMERINFO_TIMER_DISABLE;

	// Clear Interrupt Pending (must after enable)
	REG32(MIS_UMSK_ISR) = ((timerID+1)<<6);
	//Enable Timer Mode
	REG32(MIS_TC0CR+timerID*4) = TIMERINFO_TIMER_ENABLE;

    return 1;
}


/* e548 - complete */
UINT32 InitTimer1(unsigned int timerID, unsigned int dwInit)
{
    //TimerID for timer 0 / 1 only since timer 2 is SWC timer
    if (timerID >= 2) return -1;

    return InitTimer(timerID, dwInit);
}


/* e55c - complete */
UINT32 DisableTimer(UINT32 timerID)
{
    //TimerID for timer 0 / 1 only since timer 2 is SWC timer
    if (timerID >= 2) return -1;

    //timer0
	//Disable Interrupt
	REG32(MIS_TC0ICR+timerID*4) = TIMERINFO_INTERRUPT_DISABLE;

	//Disable Timer
	REG32(MIS_TC0CR+timerID*4) = TIMERINFO_TIMER_DISABLE;

    return 1;
}


/* e598 - complete */
char SystemTimeout(unsigned int timerID, unsigned int limit)
{
	char bIoStatus = FALSE;

	//TimerID for timer 0 / 1 only since timer 2 is SWC timer
	if (timerID >= 2) return FALSE;

	if (REG32(MIS_UMSK_ISR) & ((timerID+1)<<6))
	{
		bIoStatus = TRUE;
	}

	return bIoStatus;
}


/* e5c4 - complete */
void mdelay(unsigned int timerID, unsigned int dwMiniSecond)
{
    UINT32 delayTime = 0;

    //TimerID for timer 0 / 1 only since timer 2 is SWC timer
    if (timerID < 2)
    {
		delayTime = dwMiniSecond * TIMERINFO_MSEC;
		InitTimer(timerID, delayTime);
    }

    //Wait for Interrupt Pending Status
    while(SystemTimeout(timerID, delayTime) == FALSE);
}


/* e614 - complete */
void udelay(unsigned int timerID, unsigned int dwMicroSecond)
{
	UINT32 delayTime = 0;

	//TimerID for timer 0 / 1 only since timer 2 is SWC timer
	if (timerID < 2)
	{
		delayTime = dwMicroSecond * TIMERINFO_USEC;
		InitTimer(timerID, delayTime);
	}

	//Wait for Interrupt Pending Status
	while(SystemTimeout(timerID, delayTime) == FALSE);
}



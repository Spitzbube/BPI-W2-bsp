
#include "uart.h"
#include "timer.h"




/* 12b4 - todo */
int func_12b4(int* a, int* b)
{

}


/* 1338 - todo */
int func_1338(int* a, int* b)
{

}



/* 1500 - todo */
void func_1500(void)
{

}


/* de8 - todo */
void func_de8(int a)
{

}

#if 0
/* 11b4 - todo */
void func_11b4(void)
{

}
#endif

/* 3acc - todo */
int func_3acc(void* a)
{

}


/* 3674 - todo */
int func_3674(void)
{

}


/* 4844 - todo */
int func_4844(void* a)
{

}


/* 4948 - todo */
int func_4948(void)
{

}


/* 599c - todo */
int func_599c(void* a)
{

}


/* 5b94 - todo */
int func_5b94(void)
{

}


extern int Data_80005084; //80005084


/* 66b4 - todo */
void func_66b4(int a, int b)
{
	if (Data_80005084 != 0)
	{
		CP15DSB;
		CP15DMB;

		REG32(SB2_SYNC) = 0;
		CP15DMB;

		__asm_flush_dcache_range(a, b);
		CP15DMB;

		REG32(SB2_SYNC) = 0;
		CP15DMB;
	}
}


/* 6728 - todo */
void func_6728(int a)
{

}


/* 6944 - todo */
void sync(void)
{
	CP15DMB;
	//(*(volatile unsigned int *)(0x9801a020)) =0x0;
	*((unsigned int*)SB2_SYNC) = 0;
    CP15DMB;
}


/* 695c - todo */
int func_695c(void)
{

}


/* 6ae4 - todo */
int func_6ae4(void)
{

}


/* 7614 - todo */
int func_7614(int* a)
{

}


/* 73c0 - todo */
int func_73c0()
{

}


/* 77a0 - todo */
int func_77a0(int a, int b, int c, int d)
{

}


/* 7ff0 - todo */
int func_7ff0(void)
{

}


/* 77cc - todo */
int func_77cc(int* a)
{

}


/* 9458 - todo */
int func_9458(void)
{

}


/* 84d0 - todo */
int func_84d0(void)
{

}


/* 84f4 - todo */
int func_84f4(void)
{

}


/* 8534 - complete */
int func_8534(void)
{
	return 0x88120800;
}


/* 8540 - complete */
int func_8540(void)
{
	return 0;
}


/* 85e4 - todo */
void func_85e4(void* a)
{

}


/* 9570 - todo */
void func_9570(void* a)
{

}


/* c79c - complete */
void func_c79c(int a)
{
}


/* c7b8 - todo */
void func_c7b8(int a)
{

}


/* d55c - todo */
void func_d55c(void)
{

}


/* d5e0 - todo */
void func_d5e0(void)
{

}


/* d678 - todo */
void func_d678()
{

}


void func_d6a8(void* a, void* b, int c)
{

}


/* d724 - todo */
void func_d724()
{

}


void func_d7f0(char* a, void* b, int c)
{

}


/* ec7c - todo */
void func_ec7c(void)
{

}


/* e4e8 - complete */
int func_e4e8(int a)
{
	if (*((volatile unsigned int*)PWDN_CTRL2) == a)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


/* 11250 - todo */
void func_11250(void)
{

}


/* 11394 - todo */
int func_11394(void)
{

}


/* 125a0 - todo */
void func_125a0(void)
{

}


/* 12784 - todo */
void func_12784(void)
{

}


/* 12a50 - todo */
void func_12a50(int a)
{

}


/* 12d0c - todo */
int func_12d0c()
{

}



#ifndef __UTIL_H__
#define __UTIL_H__

#include "sysdefs.h"

#define UBOOT_DDR_OFFSET		0xa0000000	//for RTD299X

#define NULL		          ((void *)0)

#define NONE_SECURE_BOOT	0

#define REG32( addr )		  (*(volatile UINT32 *)(addr))

#define PARAMETER_TMP_ADDR					(0xA2400000 - UBOOT_DDR_OFFSET)

#define CODE_VAILD_MAGIC_NUMBER 0xF9E8D7C6

typedef int (*PrintFuncPtr_t)(const char *fmt, ...);
typedef void (*Flush_Dcache_AllPtr_t)(void);
typedef void (*Flush_CachePtr_t)(unsigned long start, unsigned long size);


void set_memory(void *dst, UINT8 value, UINT32 size);
extern void * memset(void * s,int c,size_t count);

#endif

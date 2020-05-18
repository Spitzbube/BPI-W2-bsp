#ifndef __UTIL_H__
#define __UTIL_H__

#include "sysdefs.h"

#define NULL		          ((void *)0)

#define REG32( addr )		  (*(volatile UINT32 *)(addr))

#define CODE_VAILD_MAGIC_NUMBER 0xF9E8D7C6

typedef int (*PrintFuncPtr_t)(const char *fmt, ...);
typedef void (*Flush_Dcache_AllPtr_t)(void);
typedef void (*Flush_CachePtr_t)(unsigned long start, unsigned long size);

#endif

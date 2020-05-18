

typedef unsigned char		UINT8;
typedef unsigned int		UINT32;

typedef unsigned long		ulong;

typedef UINT8		__u8;
typedef UINT32		__u32;

typedef	__u32		u_int32_t;

#define u32		__u32


#ifndef _SIZE_T_
#define _SIZE_T_
#ifdef __ghs__
   typedef unsigned int size_t;
#else
   typedef unsigned long size_t;
#endif
#endif


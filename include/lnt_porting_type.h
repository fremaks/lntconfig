#ifndef _LN_PORTING_type_H_
#define _LN_PORTING_type_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <linux/input.h>

#include <regex.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <net/if.h>
#include <net/if_arp.h>
#include <arpa/inet.h>

#include <termios.h>

#ifdef PRINTF_L
#undef PRINTF_L
#endif

//#define PRINTF_L ALOGI//A20的打印
//#define PRINTF_L LOGI
#define PRINTF_L printf


#define LN_DEBUG_INFO

#if 1
#ifdef LN_DEBUG_INFO

	#define LNT_PRINT_INFO   PRINTF_L
	#define LNT_PRINT_ERR    PRINTF_L
	#define LNT_PRINT_WARN   PRINTF_L
	#define LNT_PRINT_FATAL  PRINTF_L

#else

	#define LNT_PRINT_INFO   
	#define LNT_PRINT_ERR    PRINTF_L
	#define LNT_PRINT_WARN   PRINTF_L
	#define LNT_PRINT_FATAL  PRINTF_L
#endif
#else

#ifdef SRCH_DEBUG_INFO

	#define LNT_PRINT_INFO   PRINTF_L
	#define LNT_PRINT_ERR    PRINTF_L
	#define LNT_PRINT_FATAL  PRINTF_L

#else 
    #ifdef SRCH_DEBUG_ERR

	#define LNT_PRINT_INFO   
	#define LNT_PRINT_ERR    PRINTF_L
	#define LNT_PRINT_FATAL  PRINTF_L

    #else 
	    #ifdef SRCH_DEUBG_FATAL

		#define LNT_PRINT_INFO   
		#define LNT_PRINT_ERR    
		#define LNT_PRINT_FATAL  PRINTF_L

	    #else

		#define LNT_PRINT_INFO 
		#define LNT_PRINT_ERR  
		#define LNT_PRINT_FATAL

	   #endif
	#endif
#endif
#endif


///变量类型重定义

#if 0//c++中定义出错
typedef void              LNT_VOID;
#else
#define LNT_VOID          void
#endif
typedef char              LNT_S8;
typedef unsigned char	  LNT_U8;
typedef short             LNT_S16;
typedef unsigned short    LNT_U16;
typedef int               LNT_S32;
typedef unsigned int      LNT_U32;
typedef long int          LNT_LS32;
typedef unsigned long int LNT_LU32;
typedef float             LNT_F32;

typedef int             LNT_BOOL;

#ifdef _WIN32
typedef __int64         LNT_S64;
#else
typedef long long       LNT_S64;
#endif

#ifdef _WIN32
typedef unsigned __int64 LNT_U64;
#else
typedef unsigned long long LNT_U64;
#endif


typedef double     LNT_FLOAT;

#define LNT_TRUE    1
#define LNT_FALSE   0

#define LNT_NULL   (void*)0

#define LNT_SUCCESS 0
#define LNT_FAILED  -1
#define LNT_UNEXPECTED -2

#ifdef __cplusplus
}
#endif

#endif /* _LN_PORTING_type_H_ */

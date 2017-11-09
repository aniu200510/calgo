#ifndef _TYPE_H_
#define _TYPE_H_

/* 定义常用的数据类型 */


typedef int INT;	/* 占4个字节 */

typedef signed char CHAR;	/* 占1个字节 */
typedef unsigned char BYTE;	/*占1个字节 */ 

typedef signed long LONG;	/* 占4个字节 */

typedef unsigned short WORD16;	/* 占2个字节 */
typedef unsigned short WORD;	/* 占2个字节 */ 
typedef unsigned long DWORD;	/* 占4个字节 */
typedef unsigned long WORD32;	/* 占4个字节 */ 

typedef float FLOAT;	/* 占4个字节 */
typedef double DOUBLE;	/* 占8个字节 */ 

/* 定义函数结果状态 */ 
#define TRUE 1
#define FALSE 0 
#define OK 1
#define ERROR 0
#define INFEASIBLE -1

/* 定义函数类型 */
typedef void VOID; 
typedef int STATUS; 
typedef int BOOLEAN;

#endif 


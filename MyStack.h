#ifndef _MY_STACK_H_
#define _MY_STACK_H_


#define MAXSIZE 20 /* 存储空间初始分配量 */
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */


/* 定义顺序栈的的数据结构 */

typedef struct SqStack
{
	SElemType data[MAXSIZE];
	INT top; /* 用于栈顶指针 */ 
}SqStack; 

/* 定义一个空顺序栈S */
STATUS InitSqStack(SqStack *S); 

/* 清除空顺序栈S */
STATUS ClearSqStack(SqStack *S); 

/* 判断顺序栈S是否为空栈，是则返回TRUE，否则返回FALSE */
STATUS IsSqStackEmpty(SqStack S);

/* 返回顺序栈S的元素个数，即栈的长度 */
INT SqStackLength(SqStack S);

/* 如果顺序栈非空，返回栈顶元素e，成功返回TRUE，失败返回FALSE */
STATUS GetSqStackTop(SqStack S, SElemType *e); 

/* 插入元素e为新的顺序栈S顶元素，插入成功返回TRUE，否则返回FALSE */
STATUS SqStackPush(SqStack *S, SElemType e);

/* 若顺序栈非空，则弹出顺序栈S顶元素e，成功返回TRUE，失败返回FALSE */
STATUS SqStackPop(SqStack *S, SElemType *e); 

/* 从栈顶到栈顶依次显示顺序栈元素 */
STATUS SqTraverse(SqStack S);

/* 测试顺序栈 */ 
VOID TestSqStack();

/*  ----------------------------------------------------------------- */

/* 定义两栈共享空间栈结构 */
typedef struct
{
	SElemType data[MAXSIZE];
	INT top1;	/* 栈1栈顶指针 */ 
	INT top2;	/* 栈2栈顶指针 */
}DoubleStack; 

/* 初始化一个共享栈 */
STATUS InitDoubleStack(DoubleStack *S);

/* 把共享栈S设置为空栈 */
STATUS ClearDoubleStack(DoubleStack *S);
 
/* 共享栈S为空栈返回TRUE， 否则返回FALSE */
STATUS IsDoubleStackEmpty(DoubleStack S); 

/* 返回共享栈S的长度 */
INT DoubleStackLength(DoubleStack S);

/* 插入元素e为新的共享栈顶元素，stackNumber为1插入栈1，为2插入栈2  */
STATUS DoubleStackPush(DoubleStack *S, SElemType e, INT stackNumber); 

/* 删除共享栈S的栈顶元素，并用e返回stckNumber为栈号1为栈1,2为栈2 */
STATUS DoubleStackPop(DoubleStack *S, SElemType *e, INT stackNumber);

/*  ----------------------------------------------------------------- */

/* 链栈的数据结构 */

typedef struct StackNode
{
	SElemType  data;
	struct StackNode *next; 
}StackNode, *LinkStackPtr; 

typedef struct
{
	LinkStackPtr top;
	INT count;
	
}LinkStack;

/* 初始化链栈 */
STATUS InitLinkStack(LinkStack *S); 

/* 把链栈S设置为空栈 */
STATUS ClearLinkStack(LinkStack *S);

/* 链栈S为空栈，返回True，否则返回FALSE */
STATUS IsLinkStackEmpty(LinkStack S); 

/* 返回链栈S的元素个数 */
INT LinkStackLength(LinkStack S);

/* 返回链栈S的栈顶元素e */
STATUS GetLinkStackTop(LinkStack S, SElemType *e); 

/* 插入元素e为新的栈顶元素 */
STATUS LinkStackPush(LinkStack *S, SElemType e);

/* 若链栈非空，删除栈顶元素，用e返回其值，如果成功返回TRUE，否则返回FALSE */
STATUS LinkStackPop(LinkStack *S, SElemType *e);

/* 遍历打印链栈的所有元素 */
STATUS LinkStackReverse(LinkStack S);

/* 测试链栈 */
VOID TestLinkStack();

#endif


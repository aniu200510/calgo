#include <stdio.h>
#include <stdlib.h>
#include "MyType.h"
#include "MyStack.h"

/* 定义一个空栈顺序栈 */
STATUS InitSqStack(SqStack *S)
{
	if (!S)
		return ERROR;
		
	S->top = -1;
	return OK;
}

/* 把顺序栈S设置为空栈 */
STATUS ClearSqStack(SqStack *S)
{
	if (!S)
		return ERROR;
	
	S->top = -1;
	return OK;
}

/* 判断顺序栈S是否为空栈，是则返回TRUE，否则返回FALSE */
STATUS IsSqStackEmpty(SqStack S)
{
	if (-1 == S.top)
		return TRUE;
	
	return FALSE;
}

/* 返回顺序栈S的元素个数，即栈的长度 */
INT SqStackLength(SqStack S)
{
	return S.top+1;
}  

/* 如果顺序栈非空，返回栈顶元素e，成功返回TRUE，失败返回FALSE */
STATUS GetSqStackTop(SqStack S, SElemType *e)
{
	if(-1 == S.top)
		return FALSE;
	else
		*e = S.data[S.top];
		
	return TRUE;
} 

/* 插入元素e为新的顺序栈S顶元素，插入成功返回TRUE，否则返回FALSE */
STATUS SqStackPush(SqStack *S, SElemType e)
{
	if (S->top == MAXSIZE-1)	//栈满，返回FALSE 
		return FALSE;
	else
	{
		S->top++;
		S->data[S->top] = e;
	}
	return TRUE; 
} 

/* 若顺序栈非空，则弹出顺序栈S顶元素e，成功返回TRUE，失败返回FALSE */
STATUS SqStackPop(SqStack *S, SElemType *e)
{
	if (S->top == -1)
		return FALSE;
	else
	{
		*e = S->data[S->top];
		S->top--;
	}
	return TRUE;
}

/* 从栈顶到栈顶依次显示顺序栈元素 */
STATUS SqTraverse(SqStack S)
{
	int i = 0;
	
	
	if (IsSqStackEmpty(S))
	{
		printf("这是一个空顺序栈！\n");
	}
	else
	{
	
		printf("从栈底到栈顶遍历顺序栈：\n");
		while(i < S.top+1)
		{
			printf("%d ", S.data[i]);
			i++;
		}
	}
	return !(IsSqStackEmpty(S));
} 

/* 测试顺序栈 */ 
VOID TestSqStack()
{
	SqStack S;
	SElemType e;
	INT i;
	
	//初始化一个顺序栈 
	printf("初始化一个顺序栈，成功:1  失败:0，初始化结果：%d\n", InitSqStack(&S));
	
	for (i=0; i<30; i++)
	{
		SqStackPush(&S, i);
	}
	
	for (i=0; i<10; i++)
	{
		SqStackPop(&S, &e);
		printf("弹出栈顶元素e=%d, 顺序栈当前长度%d\n", e, SqStackLength(S));
	}
	GetSqStackTop(S, &e);
	printf("栈顶元素是%d\n", e);
	SqTraverse(S); 	
	printf("清空顺序栈:\n");
	ClearSqStack(&S);
	SqTraverse(S);  
} 

/* ------------------------------------------------------------------------------ */

/* 初始化一个共享栈 */
STATUS InitDoubleStack(DoubleStack *S)
{
	if (!S)
		return FALSE;
		
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return TRUE;
}

/* 把共享栈S设置为空栈 */
STATUS ClearDoubleStack(DoubleStack *S)
{
	if (!S)
		return FALSE;
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return TRUE;
} 

/* 共享栈S为空栈返回TRUE， 否则返回FALSE */
STATUS IsDoubleStackEmpty(DoubleStack S)
{
	if ((S.top1 == -1) && (S.top2 == MAXSIZE))
		return TRUE;
	else
		return FALSE;
}

/* 返回共享栈S的长度 */
INT DoubleStackLength(DoubleStack S)
{
	return (S.top1+1)+(MAXSIZE-S.top2);	
}

/* 插入元素e为新的共享栈顶元素，stackNumber为1插入栈1，为2插入栈2 */
STATUS DoubleStackPush(DoubleStack *S, SElemType e, INT stackNumber)
{
	if(S->top1+1 == S->top2) // 栈满
		return FALSE;
	
	if (stackNumber==1)
	{
		S->top1++;
		S->data[S->top1] = e;
	}
	else if (stackNumber == 2)
	{
		S->top2--;
		S->data[S->top2] = e;
	}
	
	return TRUE;	
}

/* 删除共享栈S的栈顶元素，并用e返回stckNumber为栈号1为栈1,2为栈2*/
STATUS DoubleStackPop(DoubleStack *S, SElemType *e, INT stackNumber)
{
	if(stackNumber == 1)
	{
		if (S->top1 == -1)
			return FALSE;
		else
		{
			*e = S->data[S->top1];
			S->top1--;	
		}
	}
	else if (stackNumber == 2)
	{
		if (S->top2 == MAXSIZE)
			return FALSE;
		else
		{
			*e = S->data[S->top2];
			S->top2++;
		} 
	}
	
	return TRUE;
}

/* 遍历打印共享栈 */ 
STATUS DoubleStackTraverse(DoubleStack S)
{
	int i;
	
	if (IsDoubleStackEmpty(S))
	{
		printf("共享栈为空栈");
	}
	else
	{
		i = 0;
		printf("打印共享栈1：\n");
		while(i<S.top1+1)
		{
			printf("%d ", S.data[i]);
			i++;
		}
		
		i = S.top2;
		printf("\n打印共享栈2: \n");
		while(i<MAXSIZE)
		{
			printf("%d ", S.data[i]);
			i++;
		}	
	} 
	
	return !(IsDoubleStackEmpty(S));
} 

VOID TestDoubleStack()
{
	DoubleStack S; 
	INT i;
	SElemType e;
	
	printf("初始化一个空共享栈，成功返回1，失败返回0，创建结果%d\n", InitDoubleStack(&S)); 
	for(i=1; i<8; i++)
	{
		DoubleStackPush(&S, i, 1); // 栈1中入栈8个元素 
	}
	
	for(i=1; i<8; i++)
	{
		DoubleStackPush(&S, i, 2); // 栈2中入栈8个元素 
	}
	
	DoubleStackTraverse(S); 
	printf("共享栈长度为%d\n", DoubleStackLength(S));
	
	for(i=0; i<10; i++)
	{	
		DoubleStackPop(&S, &e, 1); //栈1元素出栈 
		printf("出栈元素%d,共享栈长%d\n", e, DoubleStackLength(S)); 
	}
	ClearDoubleStack(&S);
	DoubleStackTraverse(S);
} 

/* ----------------------------------------------------------------- */

/* 初始化链栈 */
STATUS InitLinkStack(LinkStack *S)
{
	if (!S)
		return FALSE;
		
	S->count = 0;
	S->top = NULL;
	return TRUE; 
}

/* 把链栈S设置为空栈 */
STATUS ClearLinkStack(LinkStack *S)
{
	LinkStackPtr p = NULL;
	LinkStackPtr q = NULL; 
	 
	if (!S)
		return FALSE;
	
	p = S->top;
	
	while(p)
	{
		q = p; 
		p = p->next;
		free(q);
	} 
	S->top = NULL;
	S->count = 0;
	
	return TRUE;
} 

/* 链栈S为空栈，返回True，否则返回FALSE */
STATUS IsLinkStackEmpty(LinkStack S)
{
	if (S.count == 0)
		return TRUE;
	else
		return FALSE;
}

/* 返回链栈S的元素个数 */
INT LinkStackLength(LinkStack S)
{
	return S.count;
} 

/* 返回链栈S的栈顶元素e */
STATUS GetLinkStackTop(LinkStack S, SElemType *e)
{
	if(S.count == 0)
		return FALSE;
	else
		*e = S.top->data;
	
	return TRUE;
}

/* 插入元素e为新的栈顶元素 */
STATUS LinkStackPush(LinkStack *S, SElemType e)
{
	LinkStackPtr p = NULL;
	
	p = (LinkStackPtr)malloc(sizeof(StackNode));
	
	if (!p)
		return FALSE;
		
	p->data = e;
	p->next = S->top; 
	S->top = p;
	S->count++;
	
	return TRUE;
}

/* 若链栈非空，删除栈顶元素，用e返回其值，如果成功返回TRUE，否则返回FALSE */
STATUS LinkStackPop(LinkStack *S, SElemType *e)
{
	LinkStackPtr p = NULL;
	
	if (IsLinkStackEmpty(*S))
		return FALSE;
	
	*e = S->top->data; 
	p = S->top;
	S->top = p->next;
	S->count--;
	free(p);
	return TRUE; 
} 

/* 遍历打印链栈的所有元素 */
STATUS LinkStackReverse(LinkStack S)
{
	LinkStackPtr p = NULL;
	
	if (IsLinkStackEmpty(S))
	{
		printf("链栈为空\n"); 
	}
	else
	{
		printf("链栈从top->bottom为：\n");
		p = S.top;
		while(p)
		{
			printf("%d ", p->data);
			p = p->next;
		}	
	}
	
	return !(IsLinkStackEmpty(S));
} 

/* 测试链栈 */
VOID TestLinkStack()
{
	LinkStack S;
	INT i;
	SElemType e;
	
	printf("初始化链栈，初始化成功:1，失败：0,初始化结果为：%d\n", InitLinkStack(&S)); 
	
	for (i=0; i<20; i++)
	{
		/*数据入栈*/
		LinkStackPush(&S, i); 
	}
	
	for(i=0; i<10; i++)
	{
		/* 数据出栈 */
		LinkStackPop(&S, &e);
		printf("出栈元素%d,当前栈长度为%d\n", e, LinkStackLength(S)); 
	}
	e = GetLinkStackTop(S, &e);
	printf("当前栈顶元素为%d\n", e);
	LinkStackReverse(S);
	printf("\n清空链栈\n");
	ClearLinkStack(&S);
	LinkStackReverse(S);
} 


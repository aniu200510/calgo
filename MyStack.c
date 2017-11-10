#include <stdio.h>
#include <stdlib.h>
#include "MyType.h"
#include "MyStack.h"

/* ����һ����ջ˳��ջ */
STATUS InitSqStack(SqStack *S)
{
	if (!S)
		return ERROR;
		
	S->top = -1;
	return OK;
}

/* ��˳��ջS����Ϊ��ջ */
STATUS ClearSqStack(SqStack *S)
{
	if (!S)
		return ERROR;
	
	S->top = -1;
	return OK;
}

/* �ж�˳��ջS�Ƿ�Ϊ��ջ�����򷵻�TRUE�����򷵻�FALSE */
STATUS IsSqStackEmpty(SqStack S)
{
	if (-1 == S.top)
		return TRUE;
	
	return FALSE;
}

/* ����˳��ջS��Ԫ�ظ�������ջ�ĳ��� */
INT SqStackLength(SqStack S)
{
	return S.top+1;
}  

/* ���˳��ջ�ǿգ�����ջ��Ԫ��e���ɹ�����TRUE��ʧ�ܷ���FALSE */
STATUS GetSqStackTop(SqStack S, SElemType *e)
{
	if(-1 == S.top)
		return FALSE;
	else
		*e = S.data[S.top];
		
	return TRUE;
} 

/* ����Ԫ��eΪ�µ�˳��ջS��Ԫ�أ�����ɹ�����TRUE�����򷵻�FALSE */
STATUS SqStackPush(SqStack *S, SElemType e)
{
	if (S->top == MAXSIZE-1)	//ջ��������FALSE 
		return FALSE;
	else
	{
		S->top++;
		S->data[S->top] = e;
	}
	return TRUE; 
} 

/* ��˳��ջ�ǿգ��򵯳�˳��ջS��Ԫ��e���ɹ�����TRUE��ʧ�ܷ���FALSE */
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

/* ��ջ����ջ��������ʾ˳��ջԪ�� */
STATUS SqTraverse(SqStack S)
{
	int i = 0;
	
	
	if (IsSqStackEmpty(S))
	{
		printf("����һ����˳��ջ��\n");
	}
	else
	{
	
		printf("��ջ�׵�ջ������˳��ջ��\n");
		while(i < S.top+1)
		{
			printf("%d ", S.data[i]);
			i++;
		}
	}
	return !(IsSqStackEmpty(S));
} 

/* ����˳��ջ */ 
VOID TestSqStack()
{
	SqStack S;
	SElemType e;
	INT i;
	
	//��ʼ��һ��˳��ջ 
	printf("��ʼ��һ��˳��ջ���ɹ�:1  ʧ��:0����ʼ�������%d\n", InitSqStack(&S));
	
	for (i=0; i<30; i++)
	{
		SqStackPush(&S, i);
	}
	
	for (i=0; i<10; i++)
	{
		SqStackPop(&S, &e);
		printf("����ջ��Ԫ��e=%d, ˳��ջ��ǰ����%d\n", e, SqStackLength(S));
	}
	GetSqStackTop(S, &e);
	printf("ջ��Ԫ����%d\n", e);
	SqTraverse(S); 	
	printf("���˳��ջ:\n");
	ClearSqStack(&S);
	SqTraverse(S);  
} 

/* ------------------------------------------------------------------------------ */

/* ��ʼ��һ������ջ */
STATUS InitDoubleStack(DoubleStack *S)
{
	if (!S)
		return FALSE;
		
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return TRUE;
}

/* �ѹ���ջS����Ϊ��ջ */
STATUS ClearDoubleStack(DoubleStack *S)
{
	if (!S)
		return FALSE;
	S->top1 = -1;
	S->top2 = MAXSIZE;
	return TRUE;
} 

/* ����ջSΪ��ջ����TRUE�� ���򷵻�FALSE */
STATUS IsDoubleStackEmpty(DoubleStack S)
{
	if ((S.top1 == -1) && (S.top2 == MAXSIZE))
		return TRUE;
	else
		return FALSE;
}

/* ���ع���ջS�ĳ��� */
INT DoubleStackLength(DoubleStack S)
{
	return (S.top1+1)+(MAXSIZE-S.top2);	
}

/* ����Ԫ��eΪ�µĹ���ջ��Ԫ�أ�stackNumberΪ1����ջ1��Ϊ2����ջ2 */
STATUS DoubleStackPush(DoubleStack *S, SElemType e, INT stackNumber)
{
	if(S->top1+1 == S->top2) // ջ��
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

/* ɾ������ջS��ջ��Ԫ�أ�����e����stckNumberΪջ��1Ϊջ1,2Ϊջ2*/
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

/* ������ӡ����ջ */ 
STATUS DoubleStackTraverse(DoubleStack S)
{
	int i;
	
	if (IsDoubleStackEmpty(S))
	{
		printf("����ջΪ��ջ");
	}
	else
	{
		i = 0;
		printf("��ӡ����ջ1��\n");
		while(i<S.top1+1)
		{
			printf("%d ", S.data[i]);
			i++;
		}
		
		i = S.top2;
		printf("\n��ӡ����ջ2: \n");
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
	
	printf("��ʼ��һ���չ���ջ���ɹ�����1��ʧ�ܷ���0���������%d\n", InitDoubleStack(&S)); 
	for(i=1; i<8; i++)
	{
		DoubleStackPush(&S, i, 1); // ջ1����ջ8��Ԫ�� 
	}
	
	for(i=1; i<8; i++)
	{
		DoubleStackPush(&S, i, 2); // ջ2����ջ8��Ԫ�� 
	}
	
	DoubleStackTraverse(S); 
	printf("����ջ����Ϊ%d\n", DoubleStackLength(S));
	
	for(i=0; i<10; i++)
	{	
		DoubleStackPop(&S, &e, 1); //ջ1Ԫ�س�ջ 
		printf("��ջԪ��%d,����ջ��%d\n", e, DoubleStackLength(S)); 
	}
	ClearDoubleStack(&S);
	DoubleStackTraverse(S);
} 

/* ----------------------------------------------------------------- */

/* ��ʼ����ջ */
STATUS InitLinkStack(LinkStack *S)
{
	if (!S)
		return FALSE;
		
	S->count = 0;
	S->top = NULL;
	return TRUE; 
}

/* ����ջS����Ϊ��ջ */
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

/* ��ջSΪ��ջ������True�����򷵻�FALSE */
STATUS IsLinkStackEmpty(LinkStack S)
{
	if (S.count == 0)
		return TRUE;
	else
		return FALSE;
}

/* ������ջS��Ԫ�ظ��� */
INT LinkStackLength(LinkStack S)
{
	return S.count;
} 

/* ������ջS��ջ��Ԫ��e */
STATUS GetLinkStackTop(LinkStack S, SElemType *e)
{
	if(S.count == 0)
		return FALSE;
	else
		*e = S.top->data;
	
	return TRUE;
}

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
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

/* ����ջ�ǿգ�ɾ��ջ��Ԫ�أ���e������ֵ������ɹ�����TRUE�����򷵻�FALSE */
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

/* ������ӡ��ջ������Ԫ�� */
STATUS LinkStackReverse(LinkStack S)
{
	LinkStackPtr p = NULL;
	
	if (IsLinkStackEmpty(S))
	{
		printf("��ջΪ��\n"); 
	}
	else
	{
		printf("��ջ��top->bottomΪ��\n");
		p = S.top;
		while(p)
		{
			printf("%d ", p->data);
			p = p->next;
		}	
	}
	
	return !(IsLinkStackEmpty(S));
} 

/* ������ջ */
VOID TestLinkStack()
{
	LinkStack S;
	INT i;
	SElemType e;
	
	printf("��ʼ����ջ����ʼ���ɹ�:1��ʧ�ܣ�0,��ʼ�����Ϊ��%d\n", InitLinkStack(&S)); 
	
	for (i=0; i<20; i++)
	{
		/*������ջ*/
		LinkStackPush(&S, i); 
	}
	
	for(i=0; i<10; i++)
	{
		/* ���ݳ�ջ */
		LinkStackPop(&S, &e);
		printf("��ջԪ��%d,��ǰջ����Ϊ%d\n", e, LinkStackLength(S)); 
	}
	e = GetLinkStackTop(S, &e);
	printf("��ǰջ��Ԫ��Ϊ%d\n", e);
	LinkStackReverse(S);
	printf("\n�����ջ\n");
	ClearLinkStack(&S);
	LinkStackReverse(S);
} 


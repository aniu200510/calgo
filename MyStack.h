#ifndef _MY_STACK_H_
#define _MY_STACK_H_


#define MAXSIZE 20 /* �洢�ռ��ʼ������ */
typedef int SElemType; /* SElemType���͸���ʵ������������������Ϊint */


/* ����˳��ջ�ĵ����ݽṹ */

typedef struct SqStack
{
	SElemType data[MAXSIZE];
	INT top; /* ����ջ��ָ�� */ 
}SqStack; 

/* ����һ����˳��ջS */
STATUS InitSqStack(SqStack *S); 

/* �����˳��ջS */
STATUS ClearSqStack(SqStack *S); 

/* �ж�˳��ջS�Ƿ�Ϊ��ջ�����򷵻�TRUE�����򷵻�FALSE */
STATUS IsSqStackEmpty(SqStack S);

/* ����˳��ջS��Ԫ�ظ�������ջ�ĳ��� */
INT SqStackLength(SqStack S);

/* ���˳��ջ�ǿգ�����ջ��Ԫ��e���ɹ�����TRUE��ʧ�ܷ���FALSE */
STATUS GetSqStackTop(SqStack S, SElemType *e); 

/* ����Ԫ��eΪ�µ�˳��ջS��Ԫ�أ�����ɹ�����TRUE�����򷵻�FALSE */
STATUS SqStackPush(SqStack *S, SElemType e);

/* ��˳��ջ�ǿգ��򵯳�˳��ջS��Ԫ��e���ɹ�����TRUE��ʧ�ܷ���FALSE */
STATUS SqStackPop(SqStack *S, SElemType *e); 

/* ��ջ����ջ��������ʾ˳��ջԪ�� */
STATUS SqTraverse(SqStack S);

/* ����˳��ջ */ 
VOID TestSqStack();

/*  ----------------------------------------------------------------- */

/* ������ջ����ռ�ջ�ṹ */
typedef struct
{
	SElemType data[MAXSIZE];
	INT top1;	/* ջ1ջ��ָ�� */ 
	INT top2;	/* ջ2ջ��ָ�� */
}DoubleStack; 

/* ��ʼ��һ������ջ */
STATUS InitDoubleStack(DoubleStack *S);

/* �ѹ���ջS����Ϊ��ջ */
STATUS ClearDoubleStack(DoubleStack *S);
 
/* ����ջSΪ��ջ����TRUE�� ���򷵻�FALSE */
STATUS IsDoubleStackEmpty(DoubleStack S); 

/* ���ع���ջS�ĳ��� */
INT DoubleStackLength(DoubleStack S);

/* ����Ԫ��eΪ�µĹ���ջ��Ԫ�أ�stackNumberΪ1����ջ1��Ϊ2����ջ2  */
STATUS DoubleStackPush(DoubleStack *S, SElemType e, INT stackNumber); 

/* ɾ������ջS��ջ��Ԫ�أ�����e����stckNumberΪջ��1Ϊջ1,2Ϊջ2 */
STATUS DoubleStackPop(DoubleStack *S, SElemType *e, INT stackNumber);

/*  ----------------------------------------------------------------- */

/* ��ջ�����ݽṹ */

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

/* ��ʼ����ջ */
STATUS InitLinkStack(LinkStack *S); 

/* ����ջS����Ϊ��ջ */
STATUS ClearLinkStack(LinkStack *S);

/* ��ջSΪ��ջ������True�����򷵻�FALSE */
STATUS IsLinkStackEmpty(LinkStack S); 

/* ������ջS��Ԫ�ظ��� */
INT LinkStackLength(LinkStack S);

/* ������ջS��ջ��Ԫ��e */
STATUS GetLinkStackTop(LinkStack S, SElemType *e); 

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
STATUS LinkStackPush(LinkStack *S, SElemType e);

/* ����ջ�ǿգ�ɾ��ջ��Ԫ�أ���e������ֵ������ɹ�����TRUE�����򷵻�FALSE */
STATUS LinkStackPop(LinkStack *S, SElemType *e);

/* ������ӡ��ջ������Ԫ�� */
STATUS LinkStackReverse(LinkStack S);

/* ������ջ */
VOID TestLinkStack();

#endif


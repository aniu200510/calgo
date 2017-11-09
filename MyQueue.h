#ifndef _MY_QUEUE_H_
#define _MY_QUEUE_H_

typedef int QElemType;	/* QElemType���͸���ʵ������������������Ϊint */
#define MAXSIZE 20

/* ����ѭ�����е�˳��洢�ṹ */
typedef struct  
{
	QElemType data[MAXSIZE];
	INT front; /* ͷָ��*/ 
	INT rear; /* βָ�룬�����в��գ�ָ����е���һ��Ԫ�� */ 
}SqQueue;

/* ��ʼ��һ���ն��� */
STATUS InitSqQueue(SqQueue *Q); 

/* ��ѭ���������� */
STATUS ClearSqQueue(SqQueue *Q);

/* ���ѭ������Ϊ�գ�����TRUE�����򷵻�FALSE */
STATUS IsSqQueueEmpty(SqQueue Q); 

/* ����ѭ�����е�Ԫ�ظ��� */
INT SqQueueLength(SqQueue Q);

/* ���ѭ�����в�Ϊ�գ��򷵻ض�ͷ��Ԫ�� */
STATUS GetSqQueueHead(SqQueue Q, QElemType *e);

/* �����в�����������µ�Ԫ��eΪ��βԪ�� */
STATUS EnSqEnque(SqQueue *Q, QElemType e);

/* �����в�Ϊ�գ���ɾ��ѭ�����ж�ͷԪ�أ� ��e���أ����ӳɹ�����TRUE�����򷵻�FALSE */
STATUS DeSqQueue(SqQueue *Q, QElemType *e);

/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
STATUS SqQueueReverse(SqQueue Q);

/* ����ѭ������ */
VOID TestSqQueue();

/* ----------------------------------------------------------------------------------- */
/* �����еĽ��ṹ */ 
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

/* �����нṹ */
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

/* ��ʼ�������� */
STATUS InitLinkQueue(LinkQueue *Q);

/* ���������У���ɾ��ͷ��� */ 
STATUS DestoryLinkQueue(LinkQueue *Q);

/* ��������У�������ͷ��� */
STATUS ClearLinkQueue(LinkQueue *Q);

/* ��������Ϊ�գ�����TRUE�����򷵻�FALSE */
STATUS IsLinkQueueEmpty(LinkQueue Q);

/* ���������еĳ��� */
INT LinkQueueLength(LinkQueue Q); 

/* ���������ж���ͷ�ĵ�һ��Ԫ��e */
STATUS GetLinkQueueHead(LinkQueue Q, QElemType *e);

/* ����Ԫ��eΪQ���µ������ж�βԪ�� */
STATUS EnLinkQueue(LinkQueue *Q, QElemType e);

/* �����в���,ɾ��������Q�Ķ�ͷԪ��,��e������ֵ,������TRUE,���򷵻�FALSE */
STATUS DeLinkQueue(LinkQueue *Q, QElemType *e);

/* �Ӷ�ͷ����β���ζ�������Q��ÿ��Ԫ����� */
STATUS LinkQueueTraverse(LinkQueue Q);

/* ���������� */
VOID TestLinkQueue();

#endif

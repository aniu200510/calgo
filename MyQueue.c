#include <stdio.h>
#include <stdlib.h>
#include "MyType.h"
#include "MyQueue.h"


/* ��ʼ��һ����ѭ������ */
STATUS InitSqQueue(SqQueue *Q)
{
	if (!Q)
		return FALSE;
	
	Q->rear = 0;
	Q->front = 0;
	return TRUE;
} 

/* ��ѭ���������� */
STATUS ClearSqQueue(SqQueue *Q)
{
	if (!Q)
		return FALSE;
	
	Q->rear = 0;
	Q->front = 0;
	return TRUE;
} 

/* ���ѭ������Ϊ�գ�����TRUE�����򷵻�FALSE */
STATUS IsSqQueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

/* ����ѭ�����е�Ԫ�ظ��� */
INT SqQueueLength(SqQueue Q)
{
	return (Q.rear-Q.front+MAXSIZE) % MAXSIZE;
} 

/* ���ѭ�����в�Ϊ�գ��򷵻ض�ͷ��Ԫ�� */
STATUS GetSqQueueHead(SqQueue Q, QElemType *e)
{
	if (IsSqQueueEmpty(Q))
		return FALSE;
	
	*e = Q.data[Q.front];
	return TRUE;
} 

/* �����в�����������µ�Ԫ��eΪ��βԪ�� */
STATUS EnSqEnque(SqQueue *Q, QElemType e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front) // ������ 
		return FALSE;
	
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear+1)%MAXSIZE; 
	return TRUE;
} 

/* �����в�Ϊ�գ���ɾ��ѭ�����ж�ͷԪ�أ� ��e���أ����ӳɹ�����TRUE�����򷵻�FALSE */
STATUS DeSqQueue(SqQueue *Q, QElemType *e)
{
	if (IsSqQueueEmpty(*Q))
		return FALSE;
	
	*e = Q->data[Q->front];
	Q->front = (Q->front+1) % MAXSIZE;
	return TRUE;
} 

/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
STATUS SqQueueReverse(SqQueue Q)
{
	INT i;
	
	if (IsSqQueueEmpty(Q))
	{
		printf("����Ϊ��!\n");
	}
	else
	{
		printf("ѭ�����дӶ�ͷ����β����Ϊ��\n");
		i = Q.front;
		
		while(i<Q.rear)
		{
			printf("%d ", Q.data[i]);
			i = (i+1)%MAXSIZE; 
		}
		
	}
	return 	!(IsSqQueueEmpty(Q));	
}

/* ����ѭ������ */
VOID TestSqQueue()
{
	SqQueue Q;
	INT i;
	QElemType e;
	
	printf("��ʼ��ѭ�����У��ɹ���1��ʧ�ܣ�0,��ʼ�����:%d\n", InitSqQueue(&Q));
		
	
	printf("ѭ�������������:\n");
	for(i=0; i<30; i++)
	{
		EnSqEnque(&Q, i);
	}
	SqQueueReverse(Q);
	printf("ѭ���������ݳ���:\n");
	for (i=0; i<10; i++)
	{
		DeSqQueue(&Q, &e);
		printf("����Ԫ��Ϊ%d, ʣ����г���Ϊ%d\n", e, SqQueueLength(Q)); 
	} 
	e = GetSqQueueHead(Q, &e); 
	printf("��ǰ��ͷԪ��Ϊ%d\n", e);
	SqQueueReverse(Q);
	printf("\n��յ�ǰ����:\n");
	ClearSqQueue(&Q);
	SqQueueReverse(Q);
}

/* ----------------------------------------------------------------------------------- */

/* ��ʼ�������� */
STATUS InitLinkQueue(LinkQueue *Q)
{
	QueuePtr p = NULL;
	
	p = (QueuePtr)malloc(sizeof(QNode));	//����һ��ͷ��㣬����ͷָ����βָ�붼ָ�����ͷ��� 
	
	if (!p)
		return FALSE;
	
	p->next = NULL;	
	Q->front = p;
	Q->rear = p; 
	return TRUE;
}

/* ���������У���ɾ��ͷ��� */ 
STATUS DestoryLinkQueue(LinkQueue *Q)
{
	while(Q->front)
	{
		Q->rear = Q->front->next; 
		free(Q->front);
		Q->front = Q->rear;	 
	}
	return TRUE; 
}

/* ��������У�������ͷ��� */
STATUS ClearLinkQueue(LinkQueue *Q)
{
	QueuePtr p = NULL;
	QueuePtr q = NULL;  
	
	p = Q->front->next; //ָ���һ��Ԫ�� ����ͷ���ָ�����һ��Ԫ�� 
	Q->rear = Q->front; //βָ����ͷָ�붼ָ��ͷ��� 
	Q->front->next=NULL;
	while(p)
	{
		q = p;
		p = p->next;
		free(q);
	} 
	return TRUE;
}

/* ��������Ϊ�գ�����TRUE�����򷵻�FALSE */
STATUS IsLinkQueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

/* ���������еĳ��� */
INT LinkQueueLength(LinkQueue Q)
{
	QueuePtr p = NULL;
	INT length = 0;
	
	p = Q.front->next; //ָ��ͷ����ĵ�һ���������� 
	while(p)
	{
		p = p->next;
		length++;
	}
	return length;
}

/* ���������ж���ͷ�ĵ�һ��Ԫ��e */
STATUS GetLinkQueueHead(LinkQueue Q, QElemType *e)
{
	QueuePtr p = NULL;
	if (IsLinkQueueEmpty(Q))
		return FALSE;
	
	p = Q.front->next; // Q.frontָ��ͷ��㣬 Q.front->nextΪͷ����ĵ�һ������ͷ��� 
	*e = p->data;
	return TRUE;
} 

/* ����Ԫ��eΪ������Q���µĶ�βԪ�� */
STATUS EnLinkQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr p = NULL;
	
	p = (QueuePtr)malloc(sizeof(QNode));
	
	if (!p)
		return FALSE;
		
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;	/* ����β�巨��������e */ 
	Q->rear = p;
	return TRUE;
}

/* �����в���,ɾ��Q�Ķ�ͷԪ��,��e������ֵ,������TRUE,���򷵻�FALSE */
STATUS DeLinkQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p = NULL;
	
	if (IsLinkQueueEmpty(*Q)) // ��������У�ɾ��ʧ�� 
		return FALSE; 
		
	p = Q->front->next; // ָ����еĵ�һ��Ԫ�� 
	*e = p->data;
	Q->front->next = p->next; // ͷ���ָ��ڶ���Ԫ�� 
	if (Q->rear == p)
		Q->rear = Q->front;  /* ����ͷ���Ƕ�β����ɾ����rearָ��ͷ��� */ 
	free(p);
	return TRUE;
}

/* �Ӷ�ͷ����β���ζԶ���Q��ÿ��Ԫ����� */
STATUS LinkQueueTraverse(LinkQueue Q)
{
	if (IsLinkQueueEmpty(Q))
	{
		printf("�������Ϊ��!");
	}
	else
	{
		printf("��ӡ������У��Ӷ�ͷ����β�������:\n");
		Q.rear = Q.front->next;
		
		while(Q.rear)
		{
			printf("%d ", Q.rear->data);
			Q.rear = Q.rear->next;
		}
	}
	
	return TRUE;
}

/* ���������� */
VOID TestLinkQueue()
{
	LinkQueue Q;
	INT i;
	QElemType e;
	
	printf("��ʼ���������У���ʼ���ɹ���1��ʧ��0����ʼ�������%d\n", InitLinkQueue(&Q));
	for (i=1; i<30; i++)
	{
		EnLinkQueue(&Q, i*i);
	}
	LinkQueueTraverse(Q);
	printf("\n");
	for(i=0; i<10; i++)
	{
		DeLinkQueue(&Q, &e);
		printf("��ջԪ��%d ���г���Ϊ%d\n", e, LinkQueueLength(Q));
	}
	LinkQueueTraverse(Q);
	ClearLinkQueue(&Q);
	LinkQueueTraverse(Q);
	printf("���������У��ɹ�1,ʧ��0��ִ�н��:%d\n", DestoryLinkQueue(&Q));
}

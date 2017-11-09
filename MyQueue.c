#include <stdio.h>
#include <stdlib.h>
#include "MyType.h"
#include "MyQueue.h"


/* 初始化一个空循环队列 */
STATUS InitSqQueue(SqQueue *Q)
{
	if (!Q)
		return FALSE;
	
	Q->rear = 0;
	Q->front = 0;
	return TRUE;
} 

/* 将循环队列清零 */
STATUS ClearSqQueue(SqQueue *Q)
{
	if (!Q)
		return FALSE;
	
	Q->rear = 0;
	Q->front = 0;
	return TRUE;
} 

/* 如果循环队列为空，返回TRUE，否则返回FALSE */
STATUS IsSqQueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

/* 返回循环队列的元素个数 */
INT SqQueueLength(SqQueue Q)
{
	return (Q.rear-Q.front+MAXSIZE) % MAXSIZE;
} 

/* 如果循环队列不为空，则返回队头的元素 */
STATUS GetSqQueueHead(SqQueue Q, QElemType *e)
{
	if (IsSqQueueEmpty(Q))
		return FALSE;
	
	*e = Q.data[Q.front];
	return TRUE;
} 

/* 若队列不满，则插入新的元素e为队尾元素 */
STATUS EnSqEnque(SqQueue *Q, QElemType e)
{
	if ((Q->rear+1)%MAXSIZE == Q->front) // 队列满 
		return FALSE;
	
	Q->data[Q->rear] = e;
	Q->rear = (Q->rear+1)%MAXSIZE; 
	return TRUE;
} 

/* 若队列不为空，则删除循环队列队头元素， 用e返回，出队成功返回TRUE，否则返回FALSE */
STATUS DeSqQueue(SqQueue *Q, QElemType *e)
{
	if (IsSqQueueEmpty(*Q))
		return FALSE;
	
	*e = Q->data[Q->front];
	Q->front = (Q->front+1) % MAXSIZE;
	return TRUE;
} 

/* 从队头到队尾依次对队列Q中每个元素输出 */
STATUS SqQueueReverse(SqQueue Q)
{
	INT i;
	
	if (IsSqQueueEmpty(Q))
	{
		printf("队列为空!\n");
	}
	else
	{
		printf("循环队列从队头到队尾依次为：\n");
		i = Q.front;
		
		while(i<Q.rear)
		{
			printf("%d ", Q.data[i]);
			i = (i+1)%MAXSIZE; 
		}
		
	}
	return 	!(IsSqQueueEmpty(Q));	
}

/* 测试循环队列 */
VOID TestSqQueue()
{
	SqQueue Q;
	INT i;
	QElemType e;
	
	printf("初始化循环队列，成功：1，失败：0,初始化结果:%d\n", InitSqQueue(&Q));
		
	
	printf("循环队列数据入队:\n");
	for(i=0; i<30; i++)
	{
		EnSqEnque(&Q, i);
	}
	SqQueueReverse(Q);
	printf("循环队列数据出队:\n");
	for (i=0; i<10; i++)
	{
		DeSqQueue(&Q, &e);
		printf("出队元素为%d, 剩余队列长度为%d\n", e, SqQueueLength(Q)); 
	} 
	e = GetSqQueueHead(Q, &e); 
	printf("当前队头元素为%d\n", e);
	SqQueueReverse(Q);
	printf("\n清空当前队列:\n");
	ClearSqQueue(&Q);
	SqQueueReverse(Q);
}

/* ----------------------------------------------------------------------------------- */

/* 初始化链队列 */
STATUS InitLinkQueue(LinkQueue *Q)
{
	QueuePtr p = NULL;
	
	p = (QueuePtr)malloc(sizeof(QNode));	//构造一个头结点，队列头指针与尾指针都指向这个头结点 
	
	if (!p)
		return FALSE;
	
	p->next = NULL;	
	Q->front = p;
	Q->rear = p; 
	return TRUE;
}

/* 销毁链队列，并删除头结点 */ 
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

/* 清空链队列，不包括头结点 */
STATUS ClearLinkQueue(LinkQueue *Q)
{
	QueuePtr p = NULL;
	QueuePtr q = NULL;  
	
	p = Q->front->next; //指向第一个元素 ，即头结点指向的下一个元素 
	Q->rear = Q->front; //尾指针与头指针都指向头结点 
	Q->front->next=NULL;
	while(p)
	{
		q = p;
		p = p->next;
		free(q);
	} 
	return TRUE;
}

/* 若链队列为空，返回TRUE，否则返回FALSE */
STATUS IsLinkQueueEmpty(LinkQueue Q)
{
	if (Q.front == Q.rear)
		return TRUE;
	else
		return FALSE;
}

/* 返回链队列的长度 */
INT LinkQueueLength(LinkQueue Q)
{
	QueuePtr p = NULL;
	INT length = 0;
	
	p = Q.front->next; //指向头结点后的第一个队列数据 
	while(p)
	{
		p = p->next;
		length++;
	}
	return length;
}

/* 返回链队列队列头的第一个元素e */
STATUS GetLinkQueueHead(LinkQueue Q, QElemType *e)
{
	QueuePtr p = NULL;
	if (IsLinkQueueEmpty(Q))
		return FALSE;
	
	p = Q.front->next; // Q.front指向头结点， Q.front->next为头结点后的第一个队列头结点 
	*e = p->data;
	return TRUE;
} 

/* 插入元素e为链队列Q的新的队尾元素 */
STATUS EnLinkQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr p = NULL;
	
	p = (QueuePtr)malloc(sizeof(QNode));
	
	if (!p)
		return FALSE;
		
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;	/* 采用尾插法插入数据e */ 
	Q->rear = p;
	return TRUE;
}

/* 若队列不空,删除Q的队头元素,用e返回其值,并返回TRUE,否则返回FALSE */
STATUS DeLinkQueue(LinkQueue *Q, QElemType *e)
{
	QueuePtr p = NULL;
	
	if (IsLinkQueueEmpty(*Q)) // 空链表队列，删除失败 
		return FALSE; 
		
	p = Q->front->next; // 指向队列的第一个元素 
	*e = p->data;
	Q->front->next = p->next; // 头结点指向第二个元素 
	if (Q->rear == p)
		Q->rear = Q->front;  /* 若队头就是队尾，则删除后将rear指向头结点 */ 
	free(p);
	return TRUE;
}

/* 从队头到队尾依次对队列Q中每个元素输出 */
STATUS LinkQueueTraverse(LinkQueue Q)
{
	if (IsLinkQueueEmpty(Q))
	{
		printf("链表队列为空!");
	}
	else
	{
		printf("打印链表队列，从队头至队尾依次输出:\n");
		Q.rear = Q.front->next;
		
		while(Q.rear)
		{
			printf("%d ", Q.rear->data);
			Q.rear = Q.rear->next;
		}
	}
	
	return TRUE;
}

/* 测试链队列 */
VOID TestLinkQueue()
{
	LinkQueue Q;
	INT i;
	QElemType e;
	
	printf("初始化队链队列，初始化成功：1，失败0，初始化结果：%d\n", InitLinkQueue(&Q));
	for (i=1; i<30; i++)
	{
		EnLinkQueue(&Q, i*i);
	}
	LinkQueueTraverse(Q);
	printf("\n");
	for(i=0; i<10; i++)
	{
		DeLinkQueue(&Q, &e);
		printf("出栈元素%d 队列长度为%d\n", e, LinkQueueLength(Q));
	}
	LinkQueueTraverse(Q);
	ClearLinkQueue(&Q);
	LinkQueueTraverse(Q);
	printf("销毁链队列，成功1,失败0，执行结果:%d\n", DestoryLinkQueue(&Q));
}

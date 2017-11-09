#ifndef _MY_QUEUE_H_
#define _MY_QUEUE_H_

typedef int QElemType;	/* QElemType类型根据实际情况而定，这里假设为int */
#define MAXSIZE 20

/* 定义循环队列的顺序存储结构 */
typedef struct  
{
	QElemType data[MAXSIZE];
	INT front; /* 头指针*/ 
	INT rear; /* 尾指针，若队列不空，指向队列的下一个元素 */ 
}SqQueue;

/* 初始化一个空队列 */
STATUS InitSqQueue(SqQueue *Q); 

/* 将循环队列清零 */
STATUS ClearSqQueue(SqQueue *Q);

/* 如果循环队列为空，返回TRUE，否则返回FALSE */
STATUS IsSqQueueEmpty(SqQueue Q); 

/* 返回循环队列的元素个数 */
INT SqQueueLength(SqQueue Q);

/* 如果循环队列不为空，则返回队头的元素 */
STATUS GetSqQueueHead(SqQueue Q, QElemType *e);

/* 若队列不满，则插入新的元素e为队尾元素 */
STATUS EnSqEnque(SqQueue *Q, QElemType e);

/* 若队列不为空，则删除循环队列队头元素， 用e返回，出队成功返回TRUE，否则返回FALSE */
STATUS DeSqQueue(SqQueue *Q, QElemType *e);

/* 从队头到队尾依次对队列Q中每个元素输出 */
STATUS SqQueueReverse(SqQueue Q);

/* 测试循环队列 */
VOID TestSqQueue();

/* ----------------------------------------------------------------------------------- */
/* 链队列的结点结构 */ 
typedef struct QNode
{
	QElemType data;
	struct QNode *next;
}QNode, *QueuePtr;

/* 链队列结构 */
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

/* 初始化链队列 */
STATUS InitLinkQueue(LinkQueue *Q);

/* 销毁链队列，并删除头结点 */ 
STATUS DestoryLinkQueue(LinkQueue *Q);

/* 清空链队列，不包括头结点 */
STATUS ClearLinkQueue(LinkQueue *Q);

/* 若链队列为空，返回TRUE，否则返回FALSE */
STATUS IsLinkQueueEmpty(LinkQueue Q);

/* 返回链队列的长度 */
INT LinkQueueLength(LinkQueue Q); 

/* 返回链队列队列头的第一个元素e */
STATUS GetLinkQueueHead(LinkQueue Q, QElemType *e);

/* 插入元素e为Q的新的链队列队尾元素 */
STATUS EnLinkQueue(LinkQueue *Q, QElemType e);

/* 若队列不空,删除链队列Q的队头元素,用e返回其值,并返回TRUE,否则返回FALSE */
STATUS DeLinkQueue(LinkQueue *Q, QElemType *e);

/* 从队头到队尾依次对链队列Q中每个元素输出 */
STATUS LinkQueueTraverse(LinkQueue Q);

/* 测试链队列 */
VOID TestLinkQueue();

#endif

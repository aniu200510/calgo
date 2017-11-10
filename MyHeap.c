#include <stdio.h>
#include <stdlib.h>
#include "MyType.h"
#include "MyHeap.h"

/* 初始化堆 */
INT InitHeap(Heap *H)
{
	HElemType *p = NULL;
	
	p = (HElemType*)malloc(sizeof(HElemType)*HEAPNAXSIZE);
	if(!p)
		return FALSE;
	
	H->pData = p;
	H->nSize = 0;	
	return TRUE;
}

/* 采用向上渗透，堆中插入新的结点数据data */
INT InsertHeap(Heap *H, HElemType data)
{
	H->nSize++;	/* 第一个结点置空，子节点位置/2，则是父节点,实际结点数为nSize-1 */
	H->pData[H->nSize] = data; 
	IncreaseKey(H, H->nSize);
	return TRUE;
	
} 

/* 进行比较调整新插入节点的位置，因为堆是一个完全二叉树结构，pos/2是父节点位置 */
INT IncreaseKey(Heap *H, INT pos)
{
	 HElemType tmp; /* 临时变量，存取新插入结点的值*/
	 INT nParent;	/* 父节点位置 */
	 
	 while(pos > 1)
	 {
	 	tmp = H->pData[pos]; 
		nParent = pos/2;
		if(tmp > H->pData[nParent])
		{
			H->pData[pos] = H->pData[nParent];
			H->pData[nParent] = tmp;
			pos = nParent; 
		}
		else
		{
			break;
		}
	 }
	 
	 return TRUE;
}

/* 得到堆中根结点的关键字，并删除这个结点 */
INT PopMaxHeap(Heap *H)
{
	HElemType tmp; /* 临时变量，保存结点值 */
	INT pos = 1; /* 根结点下标 */ 
	INT nChild = pos *2;
	INT max = H->pData[1];
	
	while(nChild <= H->nSize)
	{
		tmp = H->pData[nChild];
		
		if(nChild+1 <= H->nSize && tmp<H->pData[nChild+1])
		{
			nChild++;
			tmp = H->pData[nChild];
		}
		H->pData[pos] = tmp;
		pos = nChild;
		nChild *= 2;
	} 
	H->pData[pos] = H->pData[H->nSize];
	H->nSize--;
	return max;
}

/*  测试堆 */
VOID TestHeap()
{
	Heap H;
	int i;
	InitHeap(&H);
	
	for(i=1;i<11; i++)
	{
		InsertHeap(&H, i);		
	}
	
	for(i=1; i<=H.nSize; i++)
	{
		printf("%d ", H.pData[i]);
	}
	printf("\n删除堆的根结点，并打印删除值:\n");
	for(i=1;i<11;i++)
	{
		printf("%d ", PopMaxHeap(&H));
	}
	printf("\n");
} 



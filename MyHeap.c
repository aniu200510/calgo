#include <stdio.h>
#include <stdlib.h>
#include "MyType.h"
#include "MyHeap.h"

/* ��ʼ���� */
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

/* ����������͸�����в����µĽ������data */
INT InsertHeap(Heap *H, HElemType data)
{
	H->nSize++;	/* ��һ������ÿգ��ӽڵ�λ��/2�����Ǹ��ڵ�,ʵ�ʽ����ΪnSize-1 */
	H->pData[H->nSize] = data; 
	IncreaseKey(H, H->nSize);
	return TRUE;
	
} 

/* ���бȽϵ����²���ڵ��λ�ã���Ϊ����һ����ȫ�������ṹ��pos/2�Ǹ��ڵ�λ�� */
INT IncreaseKey(Heap *H, INT pos)
{
	 HElemType tmp; /* ��ʱ��������ȡ�²������ֵ*/
	 INT nParent;	/* ���ڵ�λ�� */
	 
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

/* �õ����и����Ĺؼ��֣���ɾ�������� */
INT PopMaxHeap(Heap *H)
{
	HElemType tmp; /* ��ʱ������������ֵ */
	INT pos = 1; /* ������±� */ 
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

/*  ���Զ� */
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
	printf("\nɾ���ѵĸ���㣬����ӡɾ��ֵ:\n");
	for(i=1;i<11;i++)
	{
		printf("%d ", PopMaxHeap(&H));
	}
	printf("\n");
} 



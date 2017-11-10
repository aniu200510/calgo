#include <stdio.h>
#include <stdlib.h>
#include "MyType.h"
#include "MySorted.h"

/* ����˳���L���±�Ϊi��j��ֵ */
VOID swap(SortedList *L, INT i, INT j)
{
	L->temp = L->array[i];
	L->array[i] = L->array[j];
	L->array[j] = L->temp;
}

/* ð�ݷ����� */
VOID BubbleSorted(SortedList *L)
{
	int i, j;
	int count = 0;
	int cmp = 0;
	STATUS flag = TRUE;
	
	for(i=0; i<L->length-1 && flag; i++) // �����Ƚϴ���Ϊ 
	{
		flag = FALSE;
		for(j=0; j<L->length-1-i;j++)
		{
			cmp++;
			if (L->array[j]>L->array[j+1])
			{
				swap(L, j, j+1);
				flag = TRUE;	/* ��������ݽ���˵����flag����ΪTRUE������Ҫ���򣬷���˵��֮ǰ�ıȽ��Ѿ��ź����ˣ���һ��i��ѭ��������Ҫ��ִ���� */
				count++;
			}
		}
	}
	
	printf("ð�ݷ����������໥�Ƚϴ���%d,��������%d:\n", cmp, count);
}

/* ѡ������ */
VOID SelectSorted(SortedList *L)
{
	int i,j; 
	int min;
	int count = 0;
	int cmp = 0;
	
	for(i=0; i<L->length-1; i++)
	{
		min = i;
		for(j=i+1; j<L->length; j++)
		{
			cmp++;
			if(L->array[min]>L->array[j])
			{
				min = j;
			}
		}
		
		if(min != i)
		{
			count++;
			swap(L, i, min);
		}
	}
	printf("ѡ�����򷨵ıȽϴ���Ϊ%d,���ݽ�������Ϊ%d\n", cmp, count);
} 

/* �������� */
VOID InsertSorted(SortedList *L)
{
	int in, out;
	
	
	for(out = 1; out<L->length; out++)	//��Ҫ������������ݸ���
	{
		L->temp = L->array[out];
		in = out;
		while(in>0 && L->array[in-1] >= L->temp)
		{
			L->array[in] = L->array[in-1];
			in--;
		} 
		L->array[in] = L->temp;
	} 
}

/* ϣ������ */
VOID ShellSorted(SortedList *L)
{
	int gap;
	int i, j;
	
	int count=0;
	
	for(gap=L->length/2;  gap>0; gap/=2)
	{
		for(i=gap; i<L->length; i++)
		{
			j = i;
			while(j-gap>=0 && L->array[j]<L->array[j-gap])
			{
				count++;
				L->temp = L->array[j];
				L->array[j] = L->array[j-gap];
				L->array[j-gap] = L->temp;
				j-=gap;
			}
		}
	}
	printf("ϣ������Ƚϴ���count=%d\n", count);
}

/* ���������㷨 */
VOID TestSorted()
{
	int i;
	SortedList L;
	
	for (i=0; i<MAXSORTEDSIZE; i++)
	{
		L.array[i] = MAXSORTEDSIZE-i;
	}
	L.length = MAXSORTEDSIZE;
	
	printf("����ǰ����:\n"); 
	for (i=0; i<MAXSORTEDSIZE; i++)
	{
		printf("%d ", L.array[i]);
	}
	printf("\n");
	//BubbleSorted(&L);
	//SelectSorted(&L);
	printf("ð�ݷ����������:\n"); 
	for (i=0; i<MAXSORTEDSIZE; i++)
	{
		printf("%d ", L.array[i]);
	}
	printf("\n�������������:\n");
	//InsertSorted(&L);
	for (i=0; i<MAXSORTEDSIZE; i++)
	{
		printf("%d ", L.array[i]);
	}
	printf("\nϣ����������У�\n");
	ShellSorted(&L);
	for (i=0; i<MAXSORTEDSIZE; i++)
	{
		printf("%d ", L.array[i]);
	}
} 


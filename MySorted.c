#include <stdio.h>
#include <stdlib.h>
#include "MyType.h"
#include "MySorted.h"

/* 交换顺序表L中下标为i和j的值 */
VOID swap(SortedList *L, INT i, INT j)
{
	L->temp = L->array[i];
	L->array[i] = L->array[j];
	L->array[j] = L->temp;
}

/* 冒泡法排序 */
VOID BubbleSorted(SortedList *L)
{
	int i, j;
	int count = 0;
	int cmp = 0;
	STATUS flag = TRUE;
	
	for(i=0; i<L->length-1 && flag; i++) // 遍历比较次数为 
	{
		flag = FALSE;
		for(j=0; j<L->length-1-i;j++)
		{
			cmp++;
			if (L->array[j]>L->array[j+1])
			{
				swap(L, j, j+1);
				flag = TRUE;	/* 如果有数据交换说明，flag设置为TRUE，还需要排序，否则说明之前的比较已经排好序了，下一次i的循环排序不需要再执行了 */
				count++;
			}
		}
	}
	
	printf("冒泡法排序数据相互比较次数%d,交换次数%d:\n", cmp, count);
}

/* 选择排序 */
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
	printf("选择排序法的比较次数为%d,数据交换次数为%d\n", cmp, count);
} 

/* 插入排序 */
VOID InsertSorted(SortedList *L)
{
	int in, out;
	
	
	for(out = 1; out<L->length; out++)	//需要出入排序的数据个数
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

/* 希尔排序 */
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
	printf("希尔排序比较次数count=%d\n", count);
}

/* 测试排序算法 */
VOID TestSorted()
{
	int i;
	SortedList L;
	
	for (i=0; i<MAXSORTEDSIZE; i++)
	{
		L.array[i] = MAXSORTEDSIZE-i;
	}
	L.length = MAXSORTEDSIZE;
	
	printf("排序前数列:\n"); 
	for (i=0; i<MAXSORTEDSIZE; i++)
	{
		printf("%d ", L.array[i]);
	}
	printf("\n");
	//BubbleSorted(&L);
	//SelectSorted(&L);
	printf("冒泡法排序后序列:\n"); 
	for (i=0; i<MAXSORTEDSIZE; i++)
	{
		printf("%d ", L.array[i]);
	}
	printf("\n插入排序后序列:\n");
	//InsertSorted(&L);
	for (i=0; i<MAXSORTEDSIZE; i++)
	{
		printf("%d ", L.array[i]);
	}
	printf("\n希尔排序后序列：\n");
	ShellSorted(&L);
	for (i=0; i<MAXSORTEDSIZE; i++)
	{
		printf("%d ", L.array[i]);
	}
} 


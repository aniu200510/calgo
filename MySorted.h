#ifndef _MY_SORTED_H_
#define _MY_SORTED_H_

#define MAXSORTEDSIZE 10	/* 用于排序数组个数的最大值，可根据需要修改 */ 

typedef struct
{
	INT array[MAXSORTEDSIZE];	/* 用于要存储要排序的数组 */
	INT temp;	/* 临时变量 */
	INT length; /* 用来记录顺序表的长度 */ 
}SortedList;

/* 交换顺序表L中下标为i和j的值 */
VOID swap(SortedList *L, INT i, INT j); 

/* 冒泡法排序 */
VOID BubbleSorted(SortedList *L); 

/* 选择排序 */
VOID SelectSorted(SortedList *L); 

/* 插入排序 */ 
VOID InsertSorted(SortedList *L); 

/* 希尔排序 */
VOID ShellSorted(SortedList *L);

/* 测试排序算法 */
VOID TestSorted();
#endif 

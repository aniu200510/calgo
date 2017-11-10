#ifndef _MY_SORTED_H_
#define _MY_SORTED_H_

#define MAXSORTEDSIZE 10	/* ��������������������ֵ���ɸ�����Ҫ�޸� */ 

typedef struct
{
	INT array[MAXSORTEDSIZE];	/* ����Ҫ�洢Ҫ��������� */
	INT temp;	/* ��ʱ���� */
	INT length; /* ������¼˳���ĳ��� */ 
}SortedList;

/* ����˳���L���±�Ϊi��j��ֵ */
VOID swap(SortedList *L, INT i, INT j); 

/* ð�ݷ����� */
VOID BubbleSorted(SortedList *L); 

/* ѡ������ */
VOID SelectSorted(SortedList *L); 

/* �������� */ 
VOID InsertSorted(SortedList *L); 

/* ϣ������ */
VOID ShellSorted(SortedList *L);

/* ���������㷨 */
VOID TestSorted();
#endif 

#ifndef _MY_HEAP_H_
#define _MY_HEAP_H_

/* ��������ݵ��������ͣ����Զ��� */
typedef int HElemType;  

#define HEAPNAXSIZE 100

/* ����һ���ѱ��� */
typedef struct 
{
	HElemType *pData; //ָ�����ݵ�ָ��
	INT nSize; //��ǰ���н��ĸ��� 
}Heap;

/* ��ʼ���� */
INT InitHeap(Heap *H); 

/* ���в����µĽ��data */
INT InsertHeap(Heap *H, HElemType data); 

/* ���бȽϵ����²���ڵ��λ�� */
INT IncreaseKey(Heap *H, INT pos); 

/* �õ����и����Ĺؼ��֣���ɾ�������� */
INT PopMaxHeap(Heap *H); 

/*  ���Զ� */
VOID TestHeap(); 

#endif

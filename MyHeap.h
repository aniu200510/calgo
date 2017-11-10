#ifndef _MY_HEAP_H_
#define _MY_HEAP_H_

/* 定义堆数据的数据类型，可自定义 */
typedef int HElemType;  

#define HEAPNAXSIZE 100

/* 声明一个堆变量 */
typedef struct 
{
	HElemType *pData; //指向数据的指针
	INT nSize; //当前堆中结点的个数 
}Heap;

/* 初始化堆 */
INT InitHeap(Heap *H); 

/* 堆中插入新的结点data */
INT InsertHeap(Heap *H, HElemType data); 

/* 进行比较调整新插入节点的位置 */
INT IncreaseKey(Heap *H, INT pos); 

/* 得到堆中根结点的关键字，并删除这个结点 */
INT PopMaxHeap(Heap *H); 

/*  测试堆 */
VOID TestHeap(); 

#endif

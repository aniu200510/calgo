#ifndef _MY_GRAPH_H_
#define _MY_GRAPH_H_


#define MAXVEX 100 /* �������Ķ����� */
#define INFINITY 65535 /* ����һ�������ֵ */ 

typedef char VertexType[10];	/* �����������û��Զ��� */
typedef int EdgeType; /* ���ϵ�Ȩֵ����Ӧ���û����� */ 

/* �����ڽӾ�������ݽṹ */ 
typedef struct
{
	VertexType vertex[MAXVEX];	/* ����� */
	EdgeType arc[MAXVEX][MAXVEX];	/* �ڽӾ��󣬿��Կ����߱� */ 
	int vertexNums;	/* ������ */ 
	int edgeNums;	/* ���� */ 
}MGraph; 

/* ���������ڽӱ� */
VOID CreateMGraph(MGraph *G); 
/* ��ͼ�д��ڶ���v�� �򷵻����ڶ�����λ�� */
INT LocateVertex(MGraph G, VertexType v);

/* ��ӡ�����ڽ�ͼ */
VOID MGraphDisplay(MGraph G);

/* ���������ڽӱ� */
VOID TestMGraph();

/* �ڽӱ�����ݽṹ */

/* �߽�����ݽṹ */
typedef struct EdgeNode
{
	INT adjvex; /* �ڽӵ��򣬴洢���ڽӽڵ���±� */
	EdgeType weight; /* ���ڴ洢Ȩֵ*/
	struct EdgeNode *next; /* ����ָ����һ���ڽӵ� */ 
}EdgeNode; 

/* ����������ݽṹ */
typedef struct VertexNode
{
	VertexType data;
	struct EdgeNode *firstedge; /* ����ָ����һ���ڽӵ� */ 
}VertexNode; 

typedef struct
{
	VertexNode adjlist[MAXVEX]; /* �����б� */ 
	INT vertexNums; /* ������ */ 
	INT edgeNums; /* ���� */ 
}GraphAdjList; 

/* ����ͼ���ڽӱ�ṹ */
VOID CreateALGraph(GraphAdjList *G); 

/* ��ͼ�д��ڶ���v�� �򷵻����ڶ�����λ�� */ 
INT LocateALVertex(GraphAdjList G, VertexType v);

/* ��ʾ�����������ڽӱ� */
VOID ALGrphDisplay(GraphAdjList G); 
 
/* ���������ڽӱ� */
VOID TestALGraph(); 

/* ͼ��������ȱ��� */

#endif 

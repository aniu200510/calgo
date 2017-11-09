#ifndef _MY_GRAPH_H_
#define _MY_GRAPH_H_


#define MAXVEX 100 /* 定义最大的顶点数 */
#define INFINITY 65535 /* 定义一个无穷大值 */ 

typedef char VertexType[10];	/* 顶点类型有用户自定义 */
typedef int EdgeType; /* 边上的权值类型应由用户定义 */ 

/* 定义邻接矩阵的数据结构 */ 
typedef struct
{
	VertexType vertex[MAXVEX];	/* 顶点表 */
	EdgeType arc[MAXVEX][MAXVEX];	/* 邻接矩阵，可以看做边表 */ 
	int vertexNums;	/* 顶点数 */ 
	int edgeNums;	/* 边数 */ 
}MGraph; 

/* 建立无向邻接表 */
VOID CreateMGraph(MGraph *G); 
/* 若图中存在顶点v， 则返回其在顶点表的位置 */
INT LocateVertex(MGraph G, VertexType v);

/* 打印有向邻接图 */
VOID MGraphDisplay(MGraph G);

/* 测试有向邻接表 */
VOID TestMGraph();

/* 邻接表的数据结构 */

/* 边结点数据结构 */
typedef struct EdgeNode
{
	INT adjvex; /* 邻接点域，存储该邻接节点的下标 */
	EdgeType weight; /* 用于存储权值*/
	struct EdgeNode *next; /* 链域指向下一个邻接点 */ 
}EdgeNode; 

/* 顶点结点的数据结构 */
typedef struct VertexNode
{
	VertexType data;
	struct EdgeNode *firstedge; /* 链域，指向下一个邻接点 */ 
}VertexNode; 

typedef struct
{
	VertexNode adjlist[MAXVEX]; /* 顶点列表 */ 
	INT vertexNums; /* 顶点数 */ 
	INT edgeNums; /* 边数 */ 
}GraphAdjList; 

/* 建立图的邻接表结构 */
VOID CreateALGraph(GraphAdjList *G); 

/* 若图中存在顶点v， 则返回其在顶点表的位置 */ 
INT LocateALVertex(GraphAdjList G, VertexType v);

/* 显示创建的无向邻接表 */
VOID ALGrphDisplay(GraphAdjList G); 
 
/* 测试无向邻接表 */
VOID TestALGraph(); 

/* 图的深度优先编历 */

#endif 

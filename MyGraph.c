#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyType.h" 
#include "MyGraph.h"

/* 建立有向邻接表 */
VOID CreateMGraph(MGraph *G)
{
	int i, j, k;
	VertexType v1, v2;
	EdgeType weight; 
	
	printf("请输入有向邻接图的顶点数和边数(以逗号分隔):\n");
	scanf("%d,%d", &(G->vertexNums), &(G->edgeNums));
	
	printf("请输入有向邻接图的%d个顶点：\n", G->vertexNums);
	for(i=0; i<G->vertexNums; i++)
	{
		scanf("%s", G->vertex[i]);
	}
	
	printf("初始化邻接矩阵：\n");
	for (i=0; i<G->vertexNums; i++)
		for (j=0; j<G->vertexNums; j++)
			G->arc[i][j] = INFINITY;
			
	printf("读入%d条边，弧尾 弧头 权值，创建有向邻接矩阵：\n", G->edgeNums); 
	for (k=0; k<G->edgeNums; k++)
	{
		scanf("%s %s %d", v1, v2, &weight);
		i = LocateVertex(*G, v1);
		j = LocateVertex(*G, v2);
		if ((i != -1) && (j != -1))
		{
			G->arc[i][j] = weight;
		} 
	}
}

/* 若图中存在顶点v， 则返回其在顶点表的位置 */
INT LocateVertex(MGraph G, VertexType v)
{
	INT i;
	
	for(i=0; i<G.vertexNums; i++)
	{
		if (strcmp(G.vertex[i], v) == 0)
		{
			return i;
		}
	}
	
	return -1;
}

/* 打印有向邻接图 */
VOID MGraphDisplay(MGraph G) 
{
	INT i, j;
	
	printf("有向带权邻接图有%d个顶点，%d条弧\n", G.vertexNums, G.edgeNums);
	
	for(i=0; i<G.vertexNums; i++)
	{
		printf("%s ", G.vertex[i]);
	}
	
	printf("\n输出图的弧:\n");
	printf("序号i=");
	
	for(i=0; i<G.vertexNums; i++)
	{
		printf("%8d", i);
	}
	printf("\n");
	for(i=0; i<G.vertexNums; i++)
	{
		printf("%8d", i);
		for(j=0; j<G.vertexNums; j++)
		{
			printf("%8d", G.arc[i][j]);	
		}
		printf("\n");
	}
}



/* 测试有向邻接表 */
VOID TestMGraph()
{
	MGraph G;
	CreateMGraph(&G);
	MGraphDisplay(G);
} 


/* 建立图的邻接表结构 */
VOID CreateALGraph(GraphAdjList *G)
{
	int i, j, k;
	VertexType v1, v2;
	EdgeNode *p = NULL;
	
	printf("请输入无向邻接表的顶点数和边数（以逗号分隔）\n");
	scanf("%d,%d", &(G->vertexNums), &(G->edgeNums));
	
	printf("输入%d个顶点的值，初始化顶点表\n", G->vertexNums);
	for(i=0; i<G->vertexNums; i++)
	{
		scanf("%s", G->adjlist[i].data);
		G->adjlist[i].firstedge = NULL;
	}
	
	printf("输入%d个无向邻接表的弧尾 弧头\n", G->edgeNums); 
	for(k=0; k<G->edgeNums; k++)
	{
		scanf("%s %s", v1, v2); 
		p = (EdgeNode*)malloc(sizeof(EdgeNode));
		i = LocateALVertex(*G, v1);
		j = LocateALVertex(*G, v2);
		p->adjvex = j;
		p->next = G->adjlist[i].firstedge;
		G->adjlist[i].firstedge = p;
		
		p = (EdgeNode*)malloc(sizeof(EdgeNode));
		p->adjvex = i;
		p->next = G->adjlist[j].firstedge;
		G->adjlist[j].firstedge = p;
	}
}

/* 若图中存在顶点v， 则返回其在顶点表的位置 */ 
INT LocateALVertex(GraphAdjList G, VertexType v)
{
	int i;
	
	for(i=0; i<G.vertexNums; i++)
	{
		if(strcmp(G.adjlist[i].data, v) == 0)
		{
			return i;
		}
	}
	return -1; 
}

/* 显示创建的无向邻接表 */
VOID ALGrphDisplay(GraphAdjList G)
{
	EdgeNode *p = NULL;
	int i, j;
	
	printf("无向邻接表有%d个顶点，%d条边:\n", G.vertexNums, G.edgeNums); 
	for(i=0; i<G.vertexNums; i++)
	{
		p = G.adjlist[i].firstedge;
		j=0;
		while(p)
		{
			if(j==0)
			{
				printf("%s->%s", G.adjlist[i].data, G.adjlist[p->adjvex].data);
			}
			else
			{
				printf("->%s", G.adjlist[p->adjvex].data);
			}
			p =p->next;
			j++;
		}
		printf("\n");
	}
}
 
/* 测试无向邻接表 */
VOID TestALGraph()
{
	GraphAdjList G;
	
	CreateALGraph(&G);
	ALGrphDisplay(G);
}

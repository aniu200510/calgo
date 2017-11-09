#include <stdio.h>
#include <stdlib.h>
#include "MyType.h"
#include "MyGraph.h"
#include "MyStack.h"
#include "MyGraphTraverse.h"
#include "string.h"

/* 邻接矩阵的深度优先递归算法 */
VOID MGraphDFS(MGraph G, INT i)
{
	int j;
	
	visited[i] = TRUE;
	
	printf("%s ", G.vertex[i]);
	
	for(j=0; j<G.vertexNums; j++)
	{
		if((!visited[j]) && (G.arc[i][j] !=INFINITY))
			MGraphDFS(G, j);
	}
}

/* 邻接矩阵的深度遍历操作 */
VOID MGraphDFSTraverse(MGraph G)
{
	int i;
	
	
	for(i=0; i<G.vertexNums; i++)
	{
		visited[i] = FALSE;
	}
	
	for(i=0; i<G.vertexNums; i++)
	{
		if(!visited[i])
			MGraphDFS(G, i);
	}
} 

/* 邻接矩阵的深度优先测试 */
VOID TestMGraphDFS()
{
	MGraph G;
	
	CreateMGraph(&G);
	MGraphDisplay(G);
	printf("\n邻接矩阵的深度优先遍历结果:\n"); 
	MGraphDFSTraverse(G);
}



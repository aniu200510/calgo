#include <stdio.h>
#include <stdlib.h>
#include "MyType.h"
#include "MyGraph.h"
#include "MyStack.h"
#include "MyGraphTraverse.h"
#include "string.h"

/* �ڽӾ����������ȵݹ��㷨 */
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

/* �ڽӾ������ȱ������� */
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

/* �ڽӾ����������Ȳ��� */
VOID TestMGraphDFS()
{
	MGraph G;
	
	CreateMGraph(&G);
	MGraphDisplay(G);
	printf("\n�ڽӾ����������ȱ������:\n"); 
	MGraphDFSTraverse(G);
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MyType.h" 
#include "MyGraph.h"

/* ���������ڽӱ� */
VOID CreateMGraph(MGraph *G)
{
	int i, j, k;
	VertexType v1, v2;
	EdgeType weight; 
	
	printf("�����������ڽ�ͼ�Ķ������ͱ���(�Զ��ŷָ�):\n");
	scanf("%d,%d", &(G->vertexNums), &(G->edgeNums));
	
	printf("�����������ڽ�ͼ��%d�����㣺\n", G->vertexNums);
	for(i=0; i<G->vertexNums; i++)
	{
		scanf("%s", G->vertex[i]);
	}
	
	printf("��ʼ���ڽӾ���\n");
	for (i=0; i<G->vertexNums; i++)
		for (j=0; j<G->vertexNums; j++)
			G->arc[i][j] = INFINITY;
			
	printf("����%d���ߣ���β ��ͷ Ȩֵ�����������ڽӾ���\n", G->edgeNums); 
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

/* ��ͼ�д��ڶ���v�� �򷵻����ڶ�����λ�� */
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

/* ��ӡ�����ڽ�ͼ */
VOID MGraphDisplay(MGraph G) 
{
	INT i, j;
	
	printf("�����Ȩ�ڽ�ͼ��%d�����㣬%d����\n", G.vertexNums, G.edgeNums);
	
	for(i=0; i<G.vertexNums; i++)
	{
		printf("%s ", G.vertex[i]);
	}
	
	printf("\n���ͼ�Ļ�:\n");
	printf("���i=");
	
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



/* ���������ڽӱ� */
VOID TestMGraph()
{
	MGraph G;
	CreateMGraph(&G);
	MGraphDisplay(G);
} 


/* ����ͼ���ڽӱ�ṹ */
VOID CreateALGraph(GraphAdjList *G)
{
	int i, j, k;
	VertexType v1, v2;
	EdgeNode *p = NULL;
	
	printf("�����������ڽӱ�Ķ������ͱ������Զ��ŷָ���\n");
	scanf("%d,%d", &(G->vertexNums), &(G->edgeNums));
	
	printf("����%d�������ֵ����ʼ�������\n", G->vertexNums);
	for(i=0; i<G->vertexNums; i++)
	{
		scanf("%s", G->adjlist[i].data);
		G->adjlist[i].firstedge = NULL;
	}
	
	printf("����%d�������ڽӱ�Ļ�β ��ͷ\n", G->edgeNums); 
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

/* ��ͼ�д��ڶ���v�� �򷵻����ڶ�����λ�� */ 
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

/* ��ʾ�����������ڽӱ� */
VOID ALGrphDisplay(GraphAdjList G)
{
	EdgeNode *p = NULL;
	int i, j;
	
	printf("�����ڽӱ���%d�����㣬%d����:\n", G.vertexNums, G.edgeNums); 
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
 
/* ���������ڽӱ� */
VOID TestALGraph()
{
	GraphAdjList G;
	
	CreateALGraph(&G);
	ALGrphDisplay(G);
}

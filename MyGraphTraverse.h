#ifndef _MY_GRAPH_TRAVERSE_H_
#define _MY_GRAPH_TRAVERSE_H_

/* ���ʱ�־������ */
#define MAX 100
BOOLEAN visited[MAX];

/* �ڽӾ����������ȵݹ��㷨 */
VOID MGraphDFS(MGraph G, INT i); 

/* �ڽӾ������ȱ������� */
VOID MGraphDFSTraverse(MGraph G);

#endif 

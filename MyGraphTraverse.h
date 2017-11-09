#ifndef _MY_GRAPH_TRAVERSE_H_
#define _MY_GRAPH_TRAVERSE_H_

/* 访问标志的数组 */
#define MAX 100
BOOLEAN visited[MAX];

/* 邻接矩阵的深度优先递归算法 */
VOID MGraphDFS(MGraph G, INT i); 

/* 邻接矩阵的深度遍历操作 */
VOID MGraphDFSTraverse(MGraph G);

#endif 

#include <stdio.h>
#include <stdlib.h>
#include "MyType.h"
#include "MyStack.h"
#include "MyGraph.h"
#include "MyGraphTraverse.h"
#include "MySorted.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) 
{
	TestSqStack();
	TestDoubleStack();
	TestLinkStack();
	TestSqQueue();
	TestLinkQueue();
	TestMGraph();
	TestALGraph();
	TestSorted();
	TestMGraphDFS();
	return 0;
}

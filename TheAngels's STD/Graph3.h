#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#define MVNum 100
typedef int VerTexType;
using namespace std;

typedef struct ArcNode {//边结点
	int adjvex;//该边所指向的顶点的位置 
	struct ArcNode * nextarc;//指向下一条边的指针 
}ArcNode;

typedef struct VNode {//表头结点
	VerTexType data;//顶点信息      	
	ArcNode * firstarc;//指向第一条依附该顶点的边的指针 
}VNode, AdjList[MVNum];//AdjList表示邻接表类型

typedef struct {//邻接表 
	AdjList  vertices;
	int  vexnum, arcnum;//图的当前顶点数和边数 
}ALGraph;

void CreateGraph(ALGraph &G) {
	cin >> G.vexnum >> G.arcnum;
	for (int i = 0; i < G.vexnum; i++) {
		G.vertices[i].data = i;
		G.vertices[i].firstarc = NULL;
	}
	for (int i = 0; i < G.arcnum; i++) {
		int a, b;
		cin >> a >> b;
		ArcNode *add = new ArcNode();
		add->adjvex = b;
		add->nextarc = NULL;
		ArcNode *tmp = G.vertices[a].firstarc;
		if (tmp) {
			while (tmp->nextarc)
				tmp = tmp->nextarc;
			tmp->nextarc = add;
		}
		else {
			G.vertices[a].firstarc = add;
		}
	}
}

void PrintGraph(ALGraph G) {
	for (int i = 0; i < G.vexnum; i++) {
		ArcNode *tmp = G.vertices[i].firstarc;
		printf("%d", i);
		while (tmp) {
			printf("->%d", tmp->adjvex);
			tmp = tmp->nextarc;
		}
		printf("\n");
	}
}
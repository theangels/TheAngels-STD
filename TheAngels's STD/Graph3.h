#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#define MVNum 100
typedef int VerTexType;
using namespace std;

typedef struct ArcNode {//�߽��
	int adjvex;//�ñ���ָ��Ķ����λ�� 
	struct ArcNode * nextarc;//ָ����һ���ߵ�ָ�� 
}ArcNode;

typedef struct VNode {//��ͷ���
	VerTexType data;//������Ϣ      	
	ArcNode * firstarc;//ָ���һ�������ö���ıߵ�ָ�� 
}VNode, AdjList[MVNum];//AdjList��ʾ�ڽӱ�����

typedef struct {//�ڽӱ� 
	AdjList  vertices;
	int  vexnum, arcnum;//ͼ�ĵ�ǰ�������ͱ��� 
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
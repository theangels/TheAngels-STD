#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef char VerTexType;
typedef int ArcType;
#define MVNum 100
#define MaxInt 65530
typedef struct {
	VerTexType   vexs[MVNum];     //顶点表 
	ArcType   arcs[MVNum][MVNum];  //邻接矩阵 
	int  vexnum, arcnum;    //图的当前顶点数和边数 
} AMGraph;

int LocateVex(AMGraph G, VerTexType vex) {
	for (int i = 0; i < G.vexnum; i++) {
		if (vex == G.vexs[i])
			return i;
	}
	return -1;
}

void CreateGraph(AMGraph &G) {
	cin >> G.vexnum >> G.arcnum;
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			G.arcs[i][j] = MaxInt;
		}
	}
	for (int i = 0; i < G.vexnum; i++) {
		cin >> G.vexs[i];
	}
	for (int i = 0; i < G.arcnum; i++) {
		VerTexType start, end;
		int value;
		cin >> start >> end >> value;
		int a, b;
		a = LocateVex(G, start);
		b = LocateVex(G, end);
		G.arcs[a][b] = value;
	}
}

void PrintGraph(AMGraph G) {
	for (int i = 0; i < G.vexnum; i++) {
		for (int j = 0; j < G.vexnum; j++) {
			cout << G.arcs[i][j];
			if (j == G.vexnum - 1) {
				cout << endl;
			}
			else {
				cout << "\t";
			}
		}
	}
}
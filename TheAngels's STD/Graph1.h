#include<stdio.h>
#include<iostream>
using namespace std;
#define  MaxInt  32767                    	
#define  MVNum  100
#define MaxEdgeNum  1000               
typedef  char  VerTexType;    
typedef  int  ArcType;                

typedef struct{
	VerTexType vexs[MVNum];
	ArcType arcs[MVNum][MVNum];
	int vexnum,arcnum;
}AMGraph;

int LocateVex(AMGraph G,VerTexType vex){ 
	for(int i = 0; i < G.vexnum; i++){
		if(vex == G.vexs[i])
			return i;
	}
	return -1;
}

void CreateGraph(AMGraph &G){
	cin >> G.vexnum >> G.arcnum;
	for(int i = 0; i < G.vexnum; i++){
		cin >> G.vexs[i];
	}
	for(int i = 0; i < G.arcnum; i++){
		char a,b;
		int v;
		cin >> a >> b >> v;
		int x = LocateVex(G,a);
		int y = LocateVex(G,b);
		G.arcs[x][y]=G.arcs[y][x]=v;
	}
}

void PrintGraph(AMGraph G){
	for(int i = 0; i < G.vexnum; i++){
		for(int j = 0; j < G.vexnum; j++){
			cout << G.arcs[i][j];
			if(j==G.vexnum-1){
				cout << endl;
			}
			else{
				cout << " ";
			}
		}
	}
}

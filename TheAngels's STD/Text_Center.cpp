#include "Graph1.h"
typedef struct
{  
	int fromvex,endvex; 
	int weight;   
 }edge;
typedef edge edgeset[MaxEdgeNum];               

void Prim(AMGraph G, edgeset CT, VerTexType u){
	int i,j,k,t,Min,m,w;
	edge tmp;
	k = LocateVex(G,u);
	for(i = 0,j = 0; i < G.vexnum; j++){
		if(j!=k){
			CT[i].fromvex=k;
			CT[i].endvex=j;
			CT[i].weight=G.arcs[k][j];
		}
	}
	for(k = 1; k < G.vexnum; k++){
		Min = MaxInt;
		for(j = k - 1; j < G.vexnum-1; j++){
			if(CT[j].weight<Min){
				Min = CT[j].weight;
				m=j;
			}
		}
		tmp = CT[k-1];
		CT[k-1]=CT[m];
		CT[m]=tmp;
		j = CT[k-1].endvex;
		for(i = k; i < G.vexnum-1; i++){
			t = CT[i].endvex;
			w = G.arcs[j][t];
			if(w<CT[i].weight){
				CT[i].weight = w;
				CT[i].fromvex = j;
			}
		}
	}
}

void PrintEdge(edgeset CT, int n){
	cout << "fromvex\t";
	for(int i = 0; i < n; i++){
		cout << CT[i].fromvex;
		if(i==n-1){
			cout << endl;
		}
		else{
			cout << " ";
		}
	}
}

int main() {
	AMGraph tst;
	CreateGraph(tst);
	VerTexType check;
	PrintGraph(tst);
	cin >> check;
	cout << "id: " << LocateVex(tst,check) << endl;
	return 0;
}

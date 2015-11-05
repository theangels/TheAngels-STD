#include "Graph2.h"
#include<stack>

int dij[1000];
int path[1000];

void ShortestPath_DIJ(AMGraph G, int v0, int Dist[], int Path[])
{
	//用Dijkstra算法求有向网G的v0顶点到其余顶点的最短路径及
	//长度，分别存于数组 Path 和 Dist 中
	int i, n, v, w, min;
	bool S[MVNum];
	n = G.vexnum;                    //n为G中顶点的个数 
	for (v = 0; v<n; ++v) {       //n个顶点依次初始化 
		S[v] = false;                    //S初始为空集 
		Dist[v] = G.arcs[v0][v]; //初始化 v0到各终点的最短路径长度
		if (Dist[v]< MaxInt)
			Path[v] = v0;     //v0和v之间有弧，将v的前驱置为v0 
		else
			Path[v] = -1;   //如果v0和v之间无弧，则将v的前驱置为-1 
	}
	S[v0] = true;            //将v0加入S 
	Dist[v0] = 0;                //源点到源点的距离为0 	
								 //开始主循环，每次求得v0到某个顶点v的最短路径，将v加到S集
	for (i = 1; i<n; ++i) {    //对其余n?1个顶点，依次进行计算 
		min = MaxInt;
		for (w = 0; w < n; ++w) {//选择一条当前的最短路径，终点为v 
			if (!S[w] && Dist[w] < min) {
				v = w; min = Dist[w];
			}
		}
		S[v] = true;        //将v加入S 
		for (w = 0; w < n; ++w) {
			//更新从v0出发到集合V?S上所有顶点的最短路径长度 
			if (!S[w] && (Dist[v] + G.arcs[v][w] < Dist[w])) {
				Dist[w] = Dist[v] + G.arcs[v][w];        //更新D[w] 
				Path[w] = v;         //更改w的前驱为v 
			}
		}
	}
}

void PrintPath(AMGraph G, int Dist[], int Path[]) {
	for (int i = 0; i < G.vexnum; i++) {
		printf("Dist to %c is %d\n", G.vexs[i], Dist[i]);
		int tmp = i;
		stack<int> st;
		bool flag = false;
		while (tmp != -1) {
			st.push(tmp);
			tmp = Path[tmp];
		}
		while (!st.empty()) {
			if (flag) {
				printf(" ");
			}
			printf("%c", G.vexs[st.top()]);
			st.pop();
			flag = true;
		}
		printf("\n");
	}
}

int main() {
	AMGraph tst;
	CreateGraph(tst);
	PrintGraph(tst);
	VerTexType op;
	cin >> op;
	ShortestPath_DIJ(tst, LocateVex(tst,op), dij, path);
	PrintPath(tst,dij,path);
	return 0;
}

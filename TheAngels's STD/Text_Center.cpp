#include "Graph2.h"
#include<stack>

int dij[1000];
int path[1000];

void ShortestPath_DIJ(AMGraph G, int v0, int Dist[], int Path[])
{
	//��Dijkstra�㷨��������G��v0���㵽���ඥ������·����
	//���ȣ��ֱ�������� Path �� Dist ��
	int i, n, v, w, min;
	bool S[MVNum];
	n = G.vexnum;                    //nΪG�ж���ĸ��� 
	for (v = 0; v<n; ++v) {       //n���������γ�ʼ�� 
		S[v] = false;                    //S��ʼΪ�ռ� 
		Dist[v] = G.arcs[v0][v]; //��ʼ�� v0�����յ�����·������
		if (Dist[v]< MaxInt)
			Path[v] = v0;     //v0��v֮���л�����v��ǰ����Ϊv0 
		else
			Path[v] = -1;   //���v0��v֮���޻�����v��ǰ����Ϊ-1 
	}
	S[v0] = true;            //��v0����S 
	Dist[v0] = 0;                //Դ�㵽Դ��ľ���Ϊ0 	
								 //��ʼ��ѭ����ÿ�����v0��ĳ������v�����·������v�ӵ�S��
	for (i = 1; i<n; ++i) {    //������n?1�����㣬���ν��м��� 
		min = MaxInt;
		for (w = 0; w < n; ++w) {//ѡ��һ����ǰ�����·�����յ�Ϊv 
			if (!S[w] && Dist[w] < min) {
				v = w; min = Dist[w];
			}
		}
		S[v] = true;        //��v����S 
		for (w = 0; w < n; ++w) {
			//���´�v0����������V?S�����ж�������·������ 
			if (!S[w] && (Dist[v] + G.arcs[v][w] < Dist[w])) {
				Dist[w] = Dist[v] + G.arcs[v][w];        //����D[w] 
				Path[w] = v;         //����w��ǰ��Ϊv 
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

#include "TheAngels's STD.h"
#include "Binary_tree.h"
#include "LinkQueue.h"
#include "LinkList.h"
#include "Matrix.h"
#include "AdjMatrix.h"
int main(void)
{
	int n;
	cin >> n;
	AdjMatrix<char> tst(n);
	for (int i = 0; i < n; i++)
	{
		char point;
		cin >> point;
		tst.InsertVex(point);
	}
	int m;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		char pa, pb;
		cin >> pa >> pb;
		tst.InsertArc(pa, pb);
	}
	tst.PrintGraph();
	char delp;
	cin >> delp;
	tst.DeleteVex(delp);
	tst.PrintGraph();
	char da, db;
	cin >> da >> db;
	tst.DeleteArc(da, db);
	tst.PrintGraph();
}
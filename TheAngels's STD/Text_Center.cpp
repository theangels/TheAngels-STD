#include "TheAngels's STD.h"
#include "Binary_tree.h"
#include "LinkQueue.h"
#include "LinkList.h"
#include "Matrix.h"
#include "AdjMatrix.h"
#include "AdjLink.h"
int main(void)
{
	int num;
	cin >> num;
	AdjLink<char> tst(num);
	for (int i = 0; i < num; i++)
	{
		char point;
		cin >> point;
		tst.Addpoint(point);
	}
	int edge;
	cin >> edge;
	for (int i = 0; i < edge; i++)
	{
		char ta, tb;
		int val;
		cin >> ta >> tb >> val;
		tst.InsertArc(ta, tb, val);
	}
	tst.PrintGraph();
	char da, db;
	cin >> da >> db;
	tst.DeleteArc(da, db);
	tst.PrintGraph();
	char ask;
	cin >> ask;
	cout << tst.VexDegree(ask) << endl;

}
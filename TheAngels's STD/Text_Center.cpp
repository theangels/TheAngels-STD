#include"bstree.h"
int main(void) {
	bstree tst;
	ElemType in;
	ElemType m;
	in.key = 7;
	tst.PrintBST();
	tst.InsertBST(in);
	tst.PrintBST();
	tst.DeleteBST(18);
	tst.PrintBST();
	m = tst.MaxBST();
	printf("Max : %d-%d\n", m.key, m.count);
	return 0;
}
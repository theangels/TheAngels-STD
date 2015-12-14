#include"bstree.h"
int main(void) {
	bstree tst;
	ElemType in;
	in.key = 7;
	tst.PrintBST();
	tst.InsertBST(in);
	tst.PrintBST();
	tst.DeleteBST(18);
	tst.PrintBST();
	return 0;
}
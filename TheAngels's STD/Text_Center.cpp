#include "TheAngels's STD.h"
#include "Binary_tree.h"
#include "LinkQueue.h"
#include "LinkList.h"
#include "Matrix.h"
int cal(char tmp)
{
	return tmp - 'A';
}
int main(void)
{
	char A[1000 - 7];
	cin >> A;
	Binary_tree<char> tst(A);
	Binary_tree<char> tsts;
	tst.CopyBiTree(tsts);
	tsts.PreOrderTraverse2();
	return 0;
}

#include "TheAngels's STD.h"
#include "LinkList.h"
#include "LinkQueue.h"
#include "Matrix.h"
#include "SeqList.h"
#include "SeqQueue.h"
#include "SeqStack.h"
#include "binary_tree.h"
int main(void)
{
	char arr[1000 - 7];
	cin >> arr;
	Binary_tree<char> tst(arr);
	cout << tst.BiTreeDepth() << endl;
}
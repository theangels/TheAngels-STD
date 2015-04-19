#include "TheAngels's STD.h"
#include "SeqList.h"
#include "Matrix.h"
#include "LinkList.h"
int main(void)
{
	SeqList test(100);
	for (int i = 1; i <= 50; i++)
		test.insert(i, i);
	int ind;
	ElemType val;
	cin >> val >> ind;
	test.insert(val, ind);
	test.travel();
	int del;
	cin >> del;
	test.erase(del);
	test.travel();
	return 0;
}
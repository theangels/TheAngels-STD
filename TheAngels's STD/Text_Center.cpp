#include "TheAngels's STD.h"
#include "SeQList.h"
#include "Matrix.h"
#include "LinkList.h"
int main(void)
{
	Link test;
	Link_Ini(test);
	for (int i = 1; i <= 10; i++)
		Link_Add(test, i);
	Link_Traver(test);
	int ind;
	ElemType val;
	cin >> val >> ind;
	Link_Insert(test, val, ind);
	Link_Traver(test);
	int del;
	cin >> del;
	Link_Delete(test, del);
	Link_Traver(test);
	Link_Destory(test);
	return 0;
}
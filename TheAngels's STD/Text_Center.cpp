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
	Link_Traverse(test);
	int ind;
	ElemType val;
	cin >> val >> ind;
	Link_Insert(test, val, ind);
	Link_Traverse(test);
	int del;
	cin >> del;
	Link_Delete(test, del);
	Link_Traverse(test);
	int Min, Max;
	cin >> Min >> Max;
	Link_DeleteElem(test, Min, Max);
	Link_Traverse(test);
	Link_Destory(test);
	return 0;
}
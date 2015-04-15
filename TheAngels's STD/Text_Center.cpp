#include "TheAngels's STD.h"
#include "SeqList.h"
#include "Matrix.h"
#include "LinkList.h"
int main(void)
{
	LinkList tst;
	cout << "Please input the data, when meet '-1' stop" << endl;
	ElemType tmp;
	while ((cin >> tmp) && tmp != -1)
		tst.push_back(tmp);
	cout << "The LinkList's length is " << tst.size() << endl;
	cout << "The LinkList is :" << endl;
	tst.travel();
	int ind;
	cout << "Please input the delete index" << endl;
	cin >> ind;
	tst.erase(ind);
	tst.travel();
	cout << "The LinkList's length is " << tst.size() << endl;
	cout << "The LinkList is :" << endl;
	tst.travel();
	return 0;
}
#include "TheAngels's STD.h"
#include "SeqList.h"
#include "Matrix.h"
#include "LinkList.h"
int main(void)
{
	LinkList tst;
	int i = 1;
	cout << "Please input the data, stop when meet '-1'"<< endl;
	ElemType tmp;
	while ((cin >> tmp) && tmp != -1)
	tst.push_back(tmp);
	cout << "The LinkList's length is " << tst.size() << endl;
	cout << "The LinkList is :" << endl;
	tst.travel();
	int ind;
	cout << "Please input the requst index" << endl;
	cin >> ind;
	cout << tst.at(ind) << endl;
	cout << "The LinkList's length is " << tst.size() << endl;
	cout << "The LinkList is :" << endl;
	tst.travel();
	return 0;
}
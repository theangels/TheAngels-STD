#include"index.h"
int main(void) {
	IndexFind tst;
	tst.OutputIndexList();
	ElemType add;
	cin >> add.key >> add.depart;
	tst.InsertIndexList(add);
	tst.OutputIndexList();
	ElemType find;
	cin >> find.key >> find.depart;
	cout << tst.SearchIndexList(find) << endl;
}
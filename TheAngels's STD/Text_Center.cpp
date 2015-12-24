#include "sort.h"

int main(void) {
	int n;
	cin >> n;
	ScoreNode *tst = new ScoreNode[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> tst[i].name >> tst[i].score;
	}
	cout << "Before sort" << endl;
	for (int i = 1; i <= n; i++) {
		cout << tst[i].name << ":" << tst[i].score << endl;
	}
	InsertSort(tst, n);
	cout << "After sort" << endl;
	for (int i = 1; i <= n; i++) {
		cout << tst[i].name << ":" << tst[i].score << endl;
	}
}
#include"myhash.h"
int main(void) {
	int x[13];
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	myhash tst(x, n);
	tst.DispHT();
	return 0;
}
#include "TheAngels's STD.h"
#include "SeQList.h"
#include "Matrix.h"
#include "LinkList.h"
int main(void)
{
	Matrix test(2,2);
	test.at(0, 0) = 1;
	test.at(0, 1) = 1;
	test.at(1, 0) = 1;
	test.at(1, 1) = 0;
	Matrix ans(2,2);
	ans = test;
	for (int i = 1; i <= 15; i++)
	{
		ans = test ^ i;
		cout << ans.at(0, 0) << endl;
	}
	return 0;
}
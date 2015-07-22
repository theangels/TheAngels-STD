/*
#include<iostream>//暴力
#include<cstdio>//左移序列之后得到新的序列的逆序数的个数就等与当前总的个数减左边的数的逆序数a[i]，然后加上新增的逆序数n-a[i]-1
#include<cstring>
#include<algorithm>
#include<string>
const int MAX = 5001;
int s[MAX];
using namespace std;
int main()
{
	int n, m, i, j;
	__int64 sum, t, Min;
	while (cin >> n)
	{
		for (i = 0; i<n; i++)
		{
			cin >> s[i];
		}
		sum = 0;
		for (i = 0; i<n; i++)
		{
			t = 0;
			for (j = i + 1; j<n; j++)
			{
				if (s[i]>s[j])
				{
					t++;
				}
			}
			sum += t;
		}
		Min = sum;
		printf("%I64d\n", sum);
		for (i = 0; i<n; i++)
		{
			sum = sum - s[i] + (n - 1) - s[i];
			printf("%I64d\n", sum);
			if (Min>sum)
				Min = sum;
		}
		cout << Min << endl;
	}
	return 0;
}
*/
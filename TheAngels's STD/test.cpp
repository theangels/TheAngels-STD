/*
#include<iostream>//����
#include<cstdio>//��������֮��õ��µ����е��������ĸ����͵��뵱ǰ�ܵĸ�������ߵ�����������a[i]��Ȼ�����������������n-a[i]-1
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
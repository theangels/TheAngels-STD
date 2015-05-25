/*
*	Name : TheAngel's Standard Library
*	Copyright : zn373578008@icloud.com
*	Reference :	www.fateud.com
*/
//@ C Library Wrappers
#include <math.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <limits.h>
//@ Input / Output
#include <iostream>
//@ Math and Numerics
#include <algorithm>
//@ Containers
#include <map>
#include <set>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <vector>
using namespace std;
typedef long long LL;
//@ Fast Input
int Get_Int()
{
	int ret = 0, vld = 0, mius = 0;
	while (true)
	{
		int ch = getchar() - 48;
		if (ch > -1 && ch < 10)
		{
			ret = (ret << 3) + (ret << 1) + ch,
				vld = 1;
		}
		else if (ch == '-' - 48)
			mius = 1;
		else if (vld) break;
	}
	if (!mius) return ret;
	else return -ret;
}
struct Node
{
	int a, b, c, d;
};
Node ip[1000 + 5];
Node mass[50 + 5];
int main(void)
{
	int T;
	int _ = 1;
	scanf("%d", &T);
	while (T--)
	{
		printf("Case #%d:\n", _++);
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%d.%d.%d.%d", &ip[i].a, &ip[i].b, &ip[i].c, &ip[i].d);
		for (int i = 0; i < m; i++)
			scanf("%d.%d.%d.%d", &mass[i].a, &mass[i].b, &mass[i].c, &mass[i].d);
		for (int i = 0; i < m; i++)
		{
			set<LL> tst;
			for (int j = 0; j < n; j++)
			{
				long tmp = (LL)(ip[j].a&mass[i].a);
				tmp = tmp * 1000 + (LL)(ip[j].b&mass[i].b);
				tmp = tmp * 1000 + (LL)(ip[j].c&mass[i].c);
				tmp = tmp * 1000 + (LL)(ip[j].d&mass[i].d);
				tst.insert(tmp);
			}
			printf("%d\n", tst.size());
		}
	}
}
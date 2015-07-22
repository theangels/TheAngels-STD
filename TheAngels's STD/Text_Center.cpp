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
#define MAX_SIZE 100+5
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
int n, m, mlen;
int dp[100 + 5][70+5][70+5];//i j k 第i行状态为k 第i-1行状态为j
int yes[70 + 5];
int hill[100 + 5];
char mv[100 + 5][10 + 5];
inline bool check(int x)
{
	if ((x << 1) & x) return false;
	if ((x << 2) & x) return false;
	return true;
}
inline bool cs(int h, int x)
{
	if (hill[h] & x) return false;
	return true;
}
int ct(int x)
{
	int ret = 0;
	while (x)
	{
		ret++;
		x = x & (x-1);
	}
	return ret;
}
void init()
{
	mlen = 0;
	int len = (1 << m);
	for (int i = 0; i < len; i++)
	{
		if (check(i))
			yes[mlen++] = i;
	}
}
int main(void)
{
	while (scanf("%d%d", &n, &m) != EOF)
	{
		for (int i = 0; i < n; i++)
			scanf("%s", mv[i]);
		memset(dp, -1, sizeof(dp));
		init();
		for (int i = 0; i < mlen; i++)
		{
			int st = yes[i];
			if (cs(0, st))
				dp[1][1][st]=
		}
	}
}
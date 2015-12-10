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
typedef int KeyType;
typedef int InfoType;


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
//@ Count the number of the '1'
int Count_1(int x)
{
	int ret = 0;
	while (x)
	{
		ret++;
		x = x & (x - 1);
	}
	return ret;
}
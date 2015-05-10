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
#define ElemType int
using namespace std;
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
#define MAX_Sta 100000
class SeqStack
{
public:
	SeqStack() :__st()
	{
		__st = new ElemType[MAX_Sta];
		__top = __st;
	}
public:
	~SeqStack()
	{
		delete[]__st;
		__st = NULL;
		__top = NULL;
	}
public:
	bool empty()
	{
		if (__top == __st)
			return true;
		return false;
	}
public:
	int length()
	{
		return __top - __st;
	}
public:
	void push(ElemType in)
	{
		*__top = in;
		__top++;
		return;
	}
public:
	void pop()
	{
		__top--;
		return;
	}
public:
	ElemType top()
	{
		return *(__top - 1);
	}
private:
	ElemType *__st;
	ElemType *__top;
};

char check;
int main(void)
{
	SeqStack tst;
	int tmp=0;
	bool is = false;
	while (scanf_s("%c", &check, 1) && check != '=' && check != '#' && check != '\n')
	{
		if (check >= '0'&&check <= '9')
		{
			tmp = (tmp << 3) + (tmp << 1) + check - '0';
			is = true;
		}
		else if (check == ' ')
		{
			if (is)
			{
				tst.push(tmp);
				tmp = 0;
				is = false;
			}
		}
		else
		{
			int a, b, c;
			a = tst.top();
			tst.pop();
			b = tst.top();
			tst.pop();
			switch (check)
			{
			case '+':
				c = a + b;
				tst.push(c);
				break;
			case '-':
				c = a - b;
				tst.push(c);
				break;
			case '*':
				c = b * a;
				tst.push(c);
				break;
			case '/':
				c = b / a;
				tst.push(c);
				break;
			case '%':
				c = b % a;
				tst.push(c);
				break;
			}
		}
	}
	printf("%d\n", tst.top());
}
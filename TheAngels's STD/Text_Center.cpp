#include "TheAngels's STD.h"
#include "LinkList.h"
#include "Matrix.h"
#include "SeqList.h"
#include "SeqStack.h"
int main(void)
{
	string in;
	while (cin >> in)
	{
		SeqStack tst;
		int len = in.length();
		for (int i = 0; i < len / 2; i++)
			tst.push(in[i]);
		bool is = true;
		for (int i = len / 2 + ((len & 1) ? (1) : (0)); i < len; i++)
			if (tst.top() == in[i])
				tst.pop();
			else
			{
				is = false;
				break;
			}
		if (is)
			cout << "Yes!" << endl;
		else
			cout << "No!" << endl;
	}
	return 0;
}
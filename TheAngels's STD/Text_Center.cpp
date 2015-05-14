#include "TheAngels's STD.h"
#include "SeqStack.h"
#include "LinkQueue.h"
int main(void)
{
	char operate;
	int num, time;
	int full;
	cin >> full;
	SeqStack stop(full);
	LinkQueue passageway;
	while (cin >> operate >> num >> time)
	{
		if (operate == 'A')
		{
			if (stop.length() == full)
				passageway.push(num, time);
			else
			{
				ElemType add;
				add._num = num;
				add._time = time;
				stop.push(add);
			}
		}
		else
		{
			SeqStack tmp(full);
			while (stop.top()._num != num)
			{
				tmp.push(stop.top());
				stop.pop();
			}
			printf("%d\n", time - stop.top()._time);
			stop.pop();
			while (!tmp.empty())
			{
				stop.push(tmp.top());
				tmp.pop();
			}
			if (!passageway.empty())
			{
				ElemType add;
				add._num = passageway.top()._num;
				add._time = time;
				stop.push(add);
			}
		}
	}
}
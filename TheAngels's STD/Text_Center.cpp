#include "TheAngels's STD.h"
struct LQNode
{
	int _num;
	int _time;
	LQNode *next;
	LQNode() :_num(), _time(), next(){}
	LQNode(int __num, int __time, LQNode *__next = NULL) :
		_num(__num), _time(__time), next(__next){}
};
#define ElemType LQNode
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
		if (operate == 'E') break;
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
		else if (operate == 'D')
		{
			SeqStack tmp(full);
			while (stop.top()._num != num&&!stop.empty())
			{
				tmp.push(stop.top());
				stop.pop();
			}
			if (stop.empty())
				printf("Invalid instruction.\n");
			else
			{
				printf("%d\n", time - stop.top()._time);
				stop.pop();
			}
			while (!tmp.empty())
			{
				stop.push(tmp.top());
				tmp.pop();
			}
			if (!passageway.empty())
			{
				ElemType add=passageway.top();
				add._time = time;
				stop.push(add);
				passageway.pop();
			}
		}
		else
			printf("Invalid instruction.\n");
	}
	return 0;
}
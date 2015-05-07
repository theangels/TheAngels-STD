#include "TheAngels's STD.h"
#include "LinkList.h"
#include "Matrix.h"
#include "SeqList.h"
#include "SeqStack.h"
#include "SeqQueue.h"
int main(void)
{
	bool check = true;
	SeqQueue tst(1000-7);
	while (check)
	{
		cout << "Queue: 1" << endl;
		cout << "Medical: 2" << endl;
		cout << "Review: 3" << endl;
		cout << "Exit: 4" << endl;
		int flag;
		ElemType add;
		cin >> flag;
		switch (flag)
		{
		case 1:
			cin >> add;
			tst.push(add);
			break;
		case 2:
			tst.pop();
			break;
		case 3:
			tst.travel();
			break;
		case 4:
			check = false;
			break;
		default:
			cout << "Error" << endl;
		}
	}
	return 0;
}
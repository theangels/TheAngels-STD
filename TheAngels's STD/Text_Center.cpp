#include "TheAngels's STD.h"
#include "LinkList.h"
#include "Matrix.h"
#include "SeqList.h"
#include "SeqStack.h"
#include "SeqQueue.h"
int main(void)
{
	SeqList test(50);
	for (int i = 0; i < 10; i++)
	{
		int tmp = Get_Int();
		test.insert(tmp , i);
	}
	test.travel();
	return 0;
}
#include "TheAngels's STD.h"
#include "Binary_tree.h"
#include "LinkQueue.h"
#include "LinkList.h"
#include "Matrix.h"
#include "SeqList.h"
#include "SeqQueue.h"
#include "SeqStack.h"
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
int main(void)
{
	
	return 0;
}
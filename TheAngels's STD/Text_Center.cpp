#include "TheAngels's STD.h"
#include "Seqpoly.h"
#include "Linkpoly.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main(void) {
	
	Linkpoly tst;
	tst.Input(1,2);
	tst.Input(3,4);
	tst.Input(2,3);
	tst.Input(-2,3);
	tst.Input(4,5);
	tst.Delete(4);
	tst.Output();
	double ans = tst.Cal(2);
	printf("ans = %f\n", ans);
	/*---------------------------------------------------*/
	Seqpoly *tst1;
	init(tst1);
	insert(tst1,1,2);
	insert(tst1,4,5);
	insert(tst1,2,3);
	insert(tst1,3,4);
	erase(tst1,4);
	insert(tst1,-2,3);
	output(tst1);
	double ans1 = value(tst1,2);
	printf("ans1 = %f\n",ans1);
	
	return 0;
}

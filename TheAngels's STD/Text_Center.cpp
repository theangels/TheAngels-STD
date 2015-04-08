#include "TheAngels's STD.h"
#include "SeQList.h"
#include "Matrix.h"
int main(void)
{
	Matrix l, r;
	Matrix ans;
	ans.h = 3; 
	ans.l = 3;
	l.h = 3;
	l.l = 1;
	r.h = 1;
	r.l = 3;
	l.tab[0][0] = 1;
	l.tab[1][0] = 2;
	l.tab[2][0] = 3;
	r.tab[0][0] = 1;
	r.tab[0][1] = 2;
	r.tab[0][2] = 3;
	Matrix_Mult(r, l, ans);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << ans.tab[i][j] << " ";
		cout << endl;
	}
	return 0;
}